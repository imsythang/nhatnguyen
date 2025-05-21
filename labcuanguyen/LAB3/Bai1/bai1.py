"""Viết chương trình sử dụng ngôn ngữ Python thực hiện các yêu cầu sau: 
1. Hiển tất cả sinh viên 
2. Hiển thị sinh viên theo city 
3. Tìm sinh viên theo tên. 
4. Sắp xếp danh sách sinh viên theo tuổi và ghi vào file xml mới theo thứ tự đã sắp 
xếp. 
5. Thêm sinh viên mới vào và ghi lại vào file.
6. Sửa thông tin của một sinh viên bất kỳ bằng cách yêu cầu người dùng nhập vào ID 
sinh viên muốn sửa. 
7. Xóa một sinh viên và ghi lại vào file. 
"""

import xml.etree.ElementTree as ET
class Student:
    def __init__(self, id, name, age, city):
        self.id = id 
        self.name = name
        self.age = age 
        self.city = city
    def toElement(self):
        student_el = ET.Element("student")
        ET.SubElement(student_el, "id").text = self.id
        ET.SubElement(student_el, "name").text = self.name
        ET.SubElement(student_el, "age").text = self.age
        ET.SubElement(student_el, "city").text = self.city
        return student_el
class StudentManager:
    def __init__(self, filename):
        self.filename = filename
        #! Get cây -> Lấy được Root từ cây -> Lấy được các phần tử từ Root
        self.tree = ET.parse(filename)
        self.root = self.tree.getroot()
        self.students = self._loadStudents()
    def _loadStudents(self): # Chuyển Các students trong file XML thành 1 list
        students = [] # Mỗi phần tử là 1 Student
        for student in self.root.findall('student'):
            id = student.find('id').text
            name = student.find('name').text
            age = student.find('age').text
            city = student.find('city').text
            studentToAppend = Student(id, name, age, city)
            students.append(studentToAppend)
        return students
    def showAllStudent(self):
        for s in self.students:
            print(f"ID: {s.id}, Name: {s.name}, Age: {s.age}, City: {s.city}") 
    def filterByCity(self, city):
        flag = False
        for s in self.students:
            if s.city.lower() == city.lower():
                print(f"ID: {s.id}, Name: {s.name}, Age: {s.age}, City: {s.city}") 
                flag = True 
        if not flag:
            print(f"Không tìm thấy sinh viên ở thành phố {city}!")
    def filterByName(self, name):
        flag = False
        for s in self.students:
            if s.name.lower() == name.lower():
                print(f"ID: {s.id}, Name: {s.name}, Age: {s.age}, City: {s.city}") 
                flag = True  
        if not flag: 
            print(f"Không tìm thấy sinh viên có tên là {name}!")         
    def sortByAge(self, outputFile):
        self.students.sort(key=lambda x: x.age)
        #! Cách xây dựng cây: xây Root -> Thêm các phần tử vào Root -> Tạo cây 
        newRoot = ET.Element("students")
        for s in self.students:
            newRoot.append(s.toElement())
        newTree = ET.ElementTree(newRoot)
        newTree.write(outputFile, encoding="utf-8", xml_declaration = True)
        print(f"Đã ghi danh sách sắp xếp vào file {outputFile}")
    def addStudent(self, student):
        for s in self.students:
            if s.id == student.id:
                print(f"ID {student.id} đã tồn tại")
                return
        self.root.append(student.toElement())
        self.tree.write(self.filename, encoding="utf-8", xml_declaration= True)
        self.students = self._loadStudents()
        print("Đã thêm sinh viên mới vào file")
    def updateStudentByID(self, student_id):
        for s in self.root.findall("student"):
            if s.find('id').text == student_id:
                s.find("name").text = input("Tên mới: ")
                s.find("age").text = input("Tuổi mới: ")
                s.find("city").text = input("Thành phố mới: ")
                self.tree.write(self.filename, encoding="utf-8", xml_declaration=True)
                print(f"Đã cập nhật thông tin sinh viên có ID là {student_id}")
                self.students = self._loadStudents()
                return 
        print(f"Không tìm thấy sinh viên có ID là {student_id}")
    def deleteStudent(self, student_id):
        # root -> remove
        for s in self.root.findall("student"):
            if s.find("id").text == student_id:
                self.root.remove(s)
                self.tree.write(self.filename, encoding="utf-8", xml_declaration=True)
                print(f"Đã xóa sinh viên có ID là {student_id}")
                self.students = self._loadStudents()
                return 
        print(f"Không tìm thấy sinh viên có ID là {student_id}")
def menu():
    manager = StudentManager("students.xml")

    while True:
        print("\n----- MENU -----")
        print("1. Hiển thị tất cả sinh viên")
        print("2. Hiển thị sinh viên theo thành phố")
        print("3. Tìm sinh viên theo tên")
        print("4. Sắp xếp sinh viên theo tuổi và ghi vào file mới")
        print("5. Thêm sinh viên mới")
        print("6. Sửa thông tin sinh viên theo ID")
        print("7. Xóa sinh viên theo ID")
        print("0. Thoát")
        
        choice = input("Chọn chức năng: ")

        if choice == "1":
            manager.showAllStudent()
        elif choice == "2":
            city = input("Nhập thành phố cần tìm: ")
            manager.filterByCity(city)
        elif choice == "3":
            name = input("Nhập tên sinh viên cần tìm: ")
            manager.filterByName(name)
        elif choice == "4":
            outputFile = input("Nhập tên file mới để lưu danh sách đã sắp xếp: ")
            manager.sortByAge(outputFile)
        elif choice == "5":
            id = input("ID: ")
            name = input("Tên: ")
            age = input("Tuổi: ")
            city = input("Thành phố: ")
            new_student = Student(id, name, age, city)
            manager.addStudent(new_student)
        elif choice == "6":
            student_id = input("Nhập ID sinh viên cần sửa: ")
            manager.updateStudentByID(student_id)
        elif choice == "7":
            student_id = input("Nhập ID sinh viên cần xóa: ")
            manager.deleteStudent(student_id)
        elif choice == "0":
            print("Kết thúc chương trình!")
            break
        else:
            print("Lựa chọn không hợp lệ. Vui lòng chọn lại.")

# Gọi menu
menu()