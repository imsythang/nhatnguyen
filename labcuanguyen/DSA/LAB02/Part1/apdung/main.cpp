#include "Queue.h"
#include "Stack.h"
#include "linkedlist.h"
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void convertToBinary(int num) {
  Stack1 stack1;
  while (num != 0) {
    int r = num % 2;
    stack1.PushStack(r);
    num /= 2;
  }
  cout << "Số nhị phân là: ";
  while (!stack1.isEmpty()) {
    cout << stack1.PopStack();
  }
  cout << endl;
}
int rowDir[] = {1, -1, 0, 0};
int colDir[] = {0, 0, -1, 1};
bool isValid(int x, int y, int n, int m, vector<vector<int>> &matrix,
             vector<vector<bool>> visited) {
  return (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] == 1 &&
          visited[x][y] == false);
}
// Hàm tìm đường đi
bool DFS(vector<vector<int>> &matrix, int n, int m, int startX, int startY,
         int destX, int destY) {
  stack<pair<int, int>> s;
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  s.push({startX, startY});
  visited[startX][startY] = true;
  while (!s.empty()) {
    pair<int, int> current = s.top();
    s.pop();
    int x = current.first;
    int y = current.second;
    if (x == destX && y == destY) {
      cout << "Đã đến đích";
      return true;
    }
    for (int i = 0; i < 4; i++) {
      int newX = x + rowDir[i];
      int newY = y + colDir[i];
      // Check xem tọa độ mới có hợp lệ hay không
      if (isValid(newX, newY, n, m, matrix, visited)) {
        s.push({newX, newY});
        visited[newX][newY] = true;
      }
    }
  }
  cout << "Không tìm thấy đường đi";
  return false;
}
// Hàm thực hiện di chuyển toa tàu
bool rearrangeTrain(const vector<int> &target) {
  int n = target.size();
  queue<int> A;         // Đoàn tàu ban đầu
  stack<int> B;         // Trạm trung gian
  vector<int> C;        // Đoàn tàu kết quả
  vector<string> steps; // Lưu các bước di chuyển

  // Khởi tạo A với các toa từ 1 đến n
  for (int i = 1; i <= n; ++i) {
    A.push(i);
  }

  int idx = 0; // Chỉ số toa cần lấy ở target
  while (idx < n) {
    int needed = target[idx];
    // Đưa các toa từ A sang B cho đến khi toa cần tìm ở đầu A
    while (!A.empty() && A.front() != needed) {
      B.push(A.front());
      A.pop();
      steps.push_back("A->B");
    }
    // Nếu toa cần tìm ở đầu A, chuyển sang C
    if (!A.empty() && A.front() == needed) {
      A.pop();
      C.push_back(needed);
      steps.push_back("A->C");
      ++idx;
      continue;
    }
    // Nếu không còn ở A, kiểm tra trên cùng của B
    if (!B.empty() && B.top() == needed) {
      B.pop();
      C.push_back(needed);
      steps.push_back("B->C");
      ++idx;
      continue;
    }
    // Nếu không tìm thấy, không thể thực hiện
    cout << "Không thể thực hiện thứ tự này!\n";
    return false;
  }

  // In ra các bước di chuyển
  cout << "Các bước di chuyển:\n";
  for (const string &step : steps) {
    cout << step << endl;
  }
  return true;
}
bool rearrangeTrainQueue(const vector<int> &target) {
  int n = target.size();
  queue<int> A;         // Đoàn tàu ban đầu
  queue<int> B;         // Trạm trung gian (queue)
  vector<int> C;        // Đoàn tàu kết quả
  vector<string> steps; // Lưu các bước di chuyển

  // Khởi tạo A với các toa từ 1 đến n
  for (int i = 1; i <= n; ++i) {
    A.push(i);
  }

  int idx = 0; // Chỉ số toa cần lấy ở target
  while (idx < n) {
    int needed = target[idx];
    // Đưa các toa từ A sang B cho đến khi toa cần tìm ở đầu A
    while (!A.empty() && A.front() != needed) {
      B.push(A.front());
      A.pop();
      steps.push_back("A->B");
    }
    // Nếu toa cần tìm ở đầu A, chuyển sang C
    if (!A.empty() && A.front() == needed) {
      A.pop();
      C.push_back(needed);
      steps.push_back("A->C");
      ++idx;
      continue;
    }
    // Nếu không còn ở A, kiểm tra đầu B
    if (!B.empty() && B.front() == needed) {
      B.pop();
      C.push_back(needed);
      steps.push_back("B->C");
      ++idx;
      continue;
    }
    // Nếu không tìm thấy, không thể thực hiện
    cout << "Không thể thực hiện thứ tự này!\n";
    return false;
  }

  // In ra các bước di chuyển
  cout << "Các bước di chuyển:\n";
  for (const string &step : steps) {
    cout << step << endl;
  }
  return true;
}
int main() {

  // int n;
  // cout << "Nhập số lượng toa tàu: ";
  // cin >> n;
  // vector<int> target(n);
  // cout << "Nhập thứ tự mong muốn tại C (cách nhau bởi dấu cách): ";
  // for (int i = 0; i < n; ++i) {
  //   cin >> target[i];
  // }
  // bool ok = rearrangeTrain(target);
  // if (ok) {
  //   cout << "Có thể thực hiện được!" << endl;
  // } else {
  //   cout << "Không thể thực hiện!" << endl;
  // }

  int n;
  cout << "Nhập số lượng toa tàu: ";
  cin >> n;
  vector<int> target(n);
  cout << "Nhập thứ tự mong muốn tại C (cách nhau bởi dấu cách): ";
  for (int i = 0; i < n; ++i) {
    cin >> target[i];
  }
  bool ok = rearrangeTrainQueue(target);
  if (ok) {
    cout << "Có thể thực hiện được!" << endl;
  } else {
    cout << "Không thể thực hiện!" << endl;
  }
  return 0;
}
