"""
JSON (JavaScript Object Notation) là một định dạng phổ biến dùng để lưu trữ và trao đổi dữ liệu.
Cấu trúc gần giống dictionary và list trong Python.
"key" : "value"
Ví dụ:
{
    "class": {
        "name: "Python",
        "students": 20
    }
    "name": "Nhat Nguyen",
    "age": 18,
    "languages": ["C++", "Python", "Java"],
    "country": "Vietnam"
    "university": "UTH",
}
data[class][students]
import json 
1. Load file (chuyển từ json sang object của Python): json.loads
2. Load file(chuyển từ object của Python sang json): json.dumps
3. Đọc và ghi file json 
+ json.load(file) -> object Python
+ json.dump(object, file) -> json
Các thao tác: 
1. Truy cập phần tử: data["key"]
print(data["name"])
2. Thêm phần tử: data["new_key"] = "new_value"
data["University] = "UTH"
3. Xóa phần tử: del data["key"]
del data["langueges"]
4. Duyệt dữ liệu
for key, value in data.items():
    print(f"{key}: {value}")
5. Làm việc với list 
for item in data["languages"]

Giả sử có file PythonGroup.json chứa thông tin về bài viết, like, share của một nhóm 
facebook như sau
1. Hiển thị thông tin các bài viết, số lượng like, share(hiển thị tên người like, share). 
2. Tìm bài viết có số lượng like và share nhiều nhất(quy ước: like: +1, share: +2) 
3. Tìm bài viết có số lượng like nhiều nhất trong khoảng thởi gian 1h kể từ lúc post 
bài. 
4. Thêm thông tin một bài viết mới vào file(bao gồm các thông tin giống các bài viết 
cũ). 
5. Tìm và hiển thị thông tin của người có số lượng like, share nhiều nhất trong nhóm. 
CRUD - Create, Read, Update, Delete 
Thêm xóa sửa
key value
value -> {key: value}
"""
import json
from datetime import datetime, timedelta

class FacebookGroup:
    def __init__(self, filename):
        self.filename = filename
        with open(self.filename, 'r', encoding="utf-8") as file: 
            self.data = json.load(file)
    
    def showPosts(self):
        print("Thông tin các bài viết:")
        for post in self.data["group"]["posts"]:
            print(f"Post ID: {post['id']}")
            print(f"Content: {post['content']}")
            print(f"Likes: {post['likes']}")
            print(f"Shares: {post['shares']}")
            print("Liked by:", ", ".join(post["likes"]["name"]))
            
