import xml.etree.ElementTree as ET

class NetworkConfig:
    #! Get cây -> Lấy được Root từ cây -> Lấy được các phần tử từ Root
    def __init__(self, filename):
        self.filename = filename
        self.tree = ET.parse(filename)
        self.root = self.tree.getroot()    
    def show_network_info(self):
        print("Network Configuration:") 
        sessions = self.root.find('Sessions')
        for networkSession in sessions.findall('NetworkSession'):
            name = networkSession.get('name')
            enable = networkSession.get('enable')
            networkAddress = networkSession.find('NetworkAddress')
            hostIP = networkAddress.get('hostIP')
            #Tách IP và Port    
            ip, port = hostIP.split(':')
            status = "Connected" if enable == "1" else "Not Connected"
            print(f"Name: {name}, IP: {ip}, Port: {port}, Status: {status}")
    def update_network_info(self):
        sessions = self.root.find('Sessions')
        name = input("Enter the name of the network session to update: ")
        for networkSession in sessions.findall("NetworkSession"): 
            if networkSession.get("name") == name:
                newIP = input("Enter new IP: ")
                newPort = input("Enter new Port: ")
                newDesc = input("Enter new description: ")
                networkAddress = networkSession.find("NetworkAddress")
                networkAddress.set("hostIP", f"{newIP}:{newPort}") 
                networkSession.set("desc", newDesc)
                if networkSession.get("protocol") == "NDC/DDC":
                    security = networkSession.find("Security") 
                    newSSL = input("Enter new SSL: ")
                    newCert = input("Enter new serverX509CertificateName: ")
                    auth = security.find("Auth")
                    auth.set("serverX509CertificateName", newCert)
                    auth.set("sslProtocol", newSSL)
                self.tree.write(self.filename, encoding="utf-8", xml_declaration=True)
                print("Updated successfully.")
                return
        print("Network session not found.")
class TerminalConfig:
    def __init__(self, filename):
        self.filename = filename 
        self.tree = ET.parse(filename)
        self.root = self.tree.getroot()
    def show_term_info(self):
        print("Terminal Configuration:")
        terminal = self.root.find("Terminal")
        id = terminal.get("id")
        ip = terminal.find("TermIP").text
        branchNumber = terminal.find("BranchNumber").text
        terminalType = terminal.find("TerminalType").text
        print(f"ID: {id}, IP: {ip}, Branch Number: {branchNumber}, Terminal Type: {terminalType}")
    def update_ip(self):
        terminal = self.root.find("Terminal")
        newIP = input("Enter new IP: ")
        terminal.find("TermIP").text = newIP
        self.tree.write(self.filename, encoding="utf-8", xml_declaration=True)
        print("IP updated successfully.")
    def update_terminal_info(self):
        terminal = self.root.find("Terminal")
        newID = input("Enter new ID: ")
        newBranchNumber = input("Enter new Branch Number: ")
        newTerminalType = input("Enter new Terminal Type: ")
        newAutoRestartMode = input("Enter new Auto Restart Mode: ")
        terminal.set("id", newID)
        terminal.find("branchNumber").text = newBranchNumber
        terminal.find("TerminalType").text = newTerminalType
        terminal.find("AutoRestartMode").text = newAutoRestartMode
        self.tree.write(self.filename, encoding="utf-8", xml_declaration=True)
        print("Terminal information updated successfully.")
class ATMConfigManager:
    def __init__(self, network_file, terminal_file):
        self.network_config = NetworkConfig(network_file)
        self.terminal_config = TerminalConfig(terminal_file)
    def show_all_info(self):
        self.network_config.show_network_info()
        self.terminal_config.show_term_info()
    def menu(self):
        while True:
            print("\nUpdate Menu:")
            print("1. Update Network Configuration")
            print("2. Update Terminal Configuration")
            print("3. Show All Information")
            print("4. Update IP Address of ATM")
            print("0. Exit")
            choice = input("Enter your choice: ")
            if choice == "1":
                self.network_config.update_network_info()
            elif choice == "2":
                self.terminal_config.update_terminal_info()
            elif choice == "3":
                self.show_all_info()
            elif choice == "4":
                self.terminal_config.update_ip()
            elif choice == "0":
                break
            else:
                print("Invalid choice. Please try again.")
if __name__ == "__main__":
    network_file = "NetworkConf.xml"
    terminal_file = "TermConf.xml"
    atm_config_manager = ATMConfigManager(network_file, terminal_file)
    atm_config_manager.menu()
