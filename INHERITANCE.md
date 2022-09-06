# INHERITANCE
## 1. Kế thừa là gì ?

- Kế thừa (**inheritance**) là một tính chất đặc trưng của lập trình hướng đối tượng. Nó có nghĩa là một **class** thừa hưởng lại tất cả các thuộc tính, phương thức của **class** mà nó kế thừa.

- **Class** kế thừa từ một **class** khác gọi là lớp con (**childclass** hay **subclass**) hay lớp dẫn xuất (**derived class**).

- Có 2 loại kế thừa là: **Đơn kế thừa** và **Đa kế thừa**
## 1. 2. Đơn kế thừa
- Đơn kế thừa (**single inheritance**) là một **class con** kế thừa duy nhất từ một **class cha**.

- Ví dụ: **class** sinh viên chỉ kế thừa từ **class** con người.

- Cú pháp:
```cpp
class <Tên lớp dẫn xuất>: <Từ khóa dẫn xuất> <Tên lớp cơ sở> { 

}; 
```

- Note: **Từ khoá dẫn xuất** là từ khóa quy định tính chất của sự kế thừa. Có 3 từ khóa dẫn xuất là: `private`, `protected`, `public`.

- Tính chất dẫn xuất:
    - `public`: Nếu kế thừa ở dạng này, sau khi kế thừa, tất cả các thành viên dạng `public` lớp cha sẽ `public` ở lớp con, dạng `protected` ở lớp cha vẫn sẽ là `protected` ở lớp con.
    - `protected`: Nếu dùng `protected` thì sau khi kế thừa, tất cả các thành viên dạng `public` lớp cha sẽ trở thành `protected` tại lớp con.
    - `private`: Trường hợp ta sử dụng `private`, thì sau khi kế thừa, tất cả các thành viên dạng `public` và `protected` ở lớp cha sẽ thành `private` tại lớp con.

    - Ví dụ:

    ```c++
    class Base {
    public:
        int x;
    protected:
        int y;
    private:
        int z;
    };

    class PublicDerived: public Base {
    // x is public
    // y is protected
    // z is not accessible from PublicDerived
    };

    class ProtectedDerived: protected Base {
    // x is protected
    // y is protected
    // z is not accessible from ProtectedDerived
    };

    class PrivateDerived: private Base {
    // x is private
    // y is private
    // z is not accessible from PrivateDerived
    };
    ```

- **Constructor** và **Destructor** trong kế thừa:

    - Thứ tự được gọi sẽ bắt đầu từ hàm khởi tạo tương ứng của lớp cơ sở, sau đó đến hàm khởi tạo của lớp dẫn xuất. Do đó, thông thường, trong hàm khởi tạo của lớp dẫn xuất phải có hàm khởi tạo của lớp cơ sở.

    - Cú pháp khai báo hàm khởi tạo như sau:
    ```cpp
    <Tên lớp dẫn xuất>([<Các tham số>]): <Tên lớp cơ sở>([<Các đối số>]) {

    };
    ```

    - Thứ tự gọi các hàm hủy bỏ ngược với thứ tự gọi hàm thiết lập: gọi hàm hủy bỏ của lớp dẫn xuất trước khi gọi hàm hủy bỏ của lớp cơ sở.

    - Vì mỗi lớp chỉ có nhiều nhất là một hàm hủy bỏ, nên ta không cần phải chỉ ra hàm hủy bỏ nào của lớp cơ sở sẽ được gọi sau khi hủy bỏ lớp dẫn xuất. Do vậy, hàm hủy bỏ trong lớp dẫn xuất được khai báo và định nghĩa hoàn toàn giống với các lớp thông thường: 

    ```cpp
    <Tên lớp>::~<Tên lớp>([<Các tham số>]){

    }
    ```

## 1. 3. Đa kế thừa

- **Đa kế thừa (multiple inheritance)** là một lớp có thể được dẫn xuất từ nhiều lớp cơ sở khác nhau, với những kiểu dẫn xuất khác nhau.

- Cú pháp:

```cpp
class <Tên lớp dẫn xuất>: <Từ khoá dẫn xuất> <Tên lớp cơ sở 1>, 
    <Từ khoá dẫn xuất> <Tên lớp cơ sở 2>, 
    … 
    <Từ khoá dẫn xuất> <Tên lớp cơ sở n> { 
};
```

- **Constructor** và **Destructor** trong đa kế thừa:

    - Hàm khởi tạo trong đa kế thừa được khai báo tương tự như trong đơn kế thừa, ngoại trừ việc phải sắp xếp thứ tự gọi tới hàm khởi tạo của các lớp cơ sở: thông thường, thứ tự gọi đến hàm khởi tạo của các lớp cơ sở nên tuân theo thứ tự dẫn xuất từ các lớp cơ sở trong đa kế thừa.

    - Ví dụ:

    ```cpp
    class Car {
    private:
        int speed;
        string mark;
        float price;     
    public:
        Car(){
            this->speed = 0;
            this->mark = "";
            this->price = 0;
        }
        Car(int speed, string mark, float price){
            this->speed = speed;
            this->mark = mark;
            this->price = price;
        }
    };

    class PublicTransport {
        float ticket;
    public: 
        PublicTransport() {
            this->ticket = 0;
        }
        PublicTransport(float ticket){
            this->ticket = ticket;
        }
    };

    // Định nghĩa lớp Bus kế thừa từ lớp Car và PublicTransport
    class Bus: public Car, public PublicTransport {  // Thứ tự khai báo  	 
        int label; 	
    public: 
        Bus();
        Bus::Bus(int speed, string mark, float price, float ticket, int label): Car(speed, mark, price), PublicTransport(ticket) { // Theo thứ tự dẫn xuất 
            this->label = label;
        }
    };

    Bus::Bus(): Car(), PublicTransport() { 	// Theo thứ tự dẫn xuất
        label = 0; 
    }

    
    ```

    - Vì hàm huỷ bỏ là duy nhất của mỗi lớp, hơn nữa hàm huỷ bỏ của lớp cơ sở sẽ được tự động gọi đến khi giải phóng đối tượng của lớp dẫn xuất. Cho nên hàm huỷ bỏ trong đa kế thừa hoàn toàn tương tự hàm huỷ bỏ trong đơn kế thừa.

## 2. Hàm Friend

- Nếu một hàm được định nghĩa là một **hàm friend** trong C ++ thì dữ liệu là `protected` và `private` của một lớp có thể được truy cập bằng hàm này.

- Một hàm bạn của một lớp được khai báo bằng từ khóa friend khi khai báo khuôn mẫu hàm trong lớp tương ứng. 

```cpp
class <Tên lớp>{ 
    // Khai báo các thành phần lớp như thông thường 
    friend <Kiểu trả về> <Tên hàm bạn>([<Các tham số>]);
};
``` 

- Khi đó, định nghĩa chi tiết hàm bạn được thực hiện như định nghĩa một hàm tự do thông thường:

```cpp
<Kiểu trả về> <Tên hàm bạn>([<Các tham số>]) { 
    // Có thể truy nhập trực tiếp các thành phần private
}
```

- **Note:**

    - Mặc dù hàm bạn được khai báo *khuôn mẫu hàm* trong phạm vi lớp, nhưng hàm bạn tự do lại **không phải** là một phương thức của lớp. Nó là **hàm tự do**, việc định nghĩa và sử dụng hàm này hoàn toàn tương tự như các hàm tự do khác.

    - Việc khai báo *khuôn mẫu hàm* bạn trong phạm vi lớp ở vị trí nào cũng được: hàm bạn không bị ảnh hưởng bởi các từ khóa `private`, `protected` hay `public` trong lớp.

    - Trong hàm bạn, có thể truy nhập trực tiếp đến các thành phần `private` và `protected` của đối tượng có kiểu lớp mà nó làm bạn (truy nhập thông qua đối tượng cụ thể).

- Phương thức lớp là bạn của một lớp khác 
Trong C++, một phương thức của lớp này cũng có thể làm bạn của một lớp kia. Để khai báo một phương thức `f()` của lớp B là bạn của lớp A và `f()` nhận một tham số có kiểu lớp A, ta phải khai báo tuần tự như sau:

    - Khai báo khuôn mẫu lớp A, để làm tham số cho hàm f của lớp B: 

    ```cpp
    class A; 
    ```

    - Khai báo lớp B với hàm f như khai báo các lớp thông thường:

    ```cpp
    class B { 
        // Khai báo các thành phần khác của lớp B 
        void f(A); 
    };
    ```

    - Khai báo chi tiết lớp A với hàm f của lớp B là bạn

    ```cpp
    class A{ 
        // Khai báo các thành phần khác của lớp A     
        friend void B::f(A); 
    };
    ```

    - Định nghĩa chi tiết hàm f của lớp B:

    ```cpp
    void B::f(A) { 
        // Định nghĩa chi tiết hàm f 
    }
    ```

- **Note:**

    - Trong trường hợp này, **hàm f** chỉ được định nghĩa chi tiết một khi lớp A đã được định nghĩa chi tiết. Do vậy, chỉ có thể định nghĩa chi tiết **hàm f** ngay trong lớp A hoặc sau khi định nghĩa lớp A, mà không thể định nghĩa chi tiết **hàm f** ngay trong lớp B. 

    - **Hàm f** có thể truy nhập đến các thành phần `private` và `protected` của cả hai lớp A và B. Tuy nhiên, muốn **f** truy nhập đến các thành phần của lớp A thì phải thông qua một đối tượng cụ thể có kiểu lớp A. 

## 3. Nạp chồng - Overloading

- Trong một lớp, ta có thể tạo ra nhiều hàm với cùng một tên gọi nhưng khác nhau các dữ liệu đầu vào hoặc tham số, đó gọi là **nạp chồng**.

## 3. 1. Nạp chồng phương thức

- Trong một lớp, ta có thể tạo ra nhiều hàm với **cùng một tên gọi** nhưng khác nhau **các dữ liệu đầu vào hoặc tham số**, đó gọi là **nạp chồng phương thức**.

- Lới ích của việc nạp chồng phương thức là chúng ta có thể khai báo cùng một tên phương thức trong cùng chương trình, không cần phải khai báo tên khác cho cùng một hành đông.

- **Ví dụ:**

```cpp
#include <iostream>
using namespace std;

class Cal {
public:
	static int max(int a, int b) {
        int c = a;
        if (c < b) c = b;
		return c;
	}
	static int max(int a, int b, int c) {
		int d = a;
        if (d < b) d = b;
        if (d < c) d = c;
		return d;
	}
};

int main() {
	Cal C;
	cout << C.max(1, 2) << "\n";
	cout << C.max(1, 2, 3) << "\n";
}
```

**Output:**
```
2
3
```

### 3.2. Nạp chồng toán tử

- **Nạp chồng toán tử (overload operator)** là bạn định nghĩa lại toán tử đã có trên kiểu dữ liệu người dùng tự định nghĩa để dể dàng thể hiện các câu lệnh trong chương trình.

- Cú pháp:

    - Bản chất việc dùng toán tử là lời gọi hàm, do đó chúng ta overload toán tử cũng giống overload hàm. Chúng ta sẽ overload hàm có tên là `operator @`, với `@` là toán tử cần overload (+, -, *, /…), kiểu trả về của hàm chính là lớp đó.

    - Có 2 loại là: **hàm cục bộ (dùng phương thức của lớp)** và **hàm toàn cục (dùng hàm bạn)**.

    - Ví dụ:

    ```cpp
    #include<iostream>
    using namespace std;

    class SoPhuc {
    private:
        int thuc, ao;
    public:
        SoPhuc(): thuc(), ao() {}

        SoPhuc(int thuc, int ao) {
            this->thuc = thuc;
            this->ao = ao;
        }

        SoPhuc operator + (SoPhuc sp) {
            SoPhuc kq;
            kq.thuc = this->thuc + sp.thuc;
            kq.ao = this->ao + sp.ao;
            return kq;
        }

        void display() {
            cout << thuc << " " << ao;
        }
    };

    int main() {
        SoPhuc sp1(1, 2);
        SoPhuc sp2(2, 3);
        SoPhuc sp3 = sp1 + sp2;
        sp3.display();
    }
    ```

    **Output:**
    ```
    3 5
    ```

    - Chuyển kiểu

        - Nếu không tìm thấy phiên bản nạp chồng toán tử nào phù hợp với kiểu dữ liệu của toán hạng, trình biên dịch sẽ chuyển đối toán hạng **sang kiểu dữ liệu cơ bản** để tính toán. Vậy chúng ta sẽ cần overload toán tử chuyển kiểu để trình biên dịch có thể chuyển kiểu dữ liệu ta định nghĩa sang kiểu dữ liệu cơ bản.

        - Ví dụ:

        ```cpp
        // Ví dụ overload toán tử chuyển kiểu float
        class PhanSo {
            operator float();
        }

        PhanSo::operator float() {
            return (float)this->tu / this->mau;
        }
        ```

        - Để hạn chế việc phải overload toán tử với các toán hạng có kiểu dữ liệu khác nhau, ta sử dụng **chuyển kiểu bằng constructor**
        - Ví dụ:

        ```cpp
        // constructor
        PhanSo(int tu) : tu(tu), mau(1) {}
        ```

        - Với constructor được khai báo như trên, khi ta thực hiện cộng một số nguyên với một kiểu phân số, số nguyên sẽ được trình biên dịch chuyển thành kiểu phân số thông qua việc gọi constructor bên trên, với mẫu số là 1 và tử chính là toán hạng ta đang cộng.

        - **Note**: Sự nhập nhằng xảy ra khi bạn thực hiện chuyển kiểu bằng constructor và chuyển kiểu bằng toán tử chuyển kiểu. Sự nhập nhằng khiến cho trình biên dịch không xác định được nên chuyển kiểu bằng toán tử chuyển kiểu hay constructor, dẫn đến việc mất đi cơ chế chuyển kiểu tự động

    - Overload toán tử nhập, xuất:

        - **Toán tử nhập:**

        ```cpp
        class SoPhuc {
            friend istream &operator >> (istream &in, SoPhuc &sp);
        }

        istream &operator >> (istream &in, SoPhuc &sp) {
            cout << "Thuc: ";
            in >> sp.thuc;
            cout << "Ao: ";
            in >> sp.ao;
            return in;
        }
        ```

        **Toán tử xuất:**

        ```cpp
        class SoPhuc {
            friend ostream &operator << (ostream &out, SoPhuc sp);
        }

        ostream &operator << (ostream &out, SoPhuc sp) {
            out << sp.thuc << " + " << sp.ao << "i";
        }
        ```

## 4. Ghi đè - Overriding

- Nếu lớp dẫn xuất định nghĩa cùng một phương thức đã được định nghĩa trong lớp cơ sở của nó, được gọi là **phương thức ghi đè** trong C++. Phương thức ghi đè cho phép bạn cung cấp việc thực hiện cụ thể chức năng đã được lớp cơ sở của nó cung cấp.

- Overriding thường được sử dụng trong method ở **lớp con**.

- Ví dụ:

```cpp
#include <iostream>  
using namespace std;

class Person {
public:
	void work() {
		cout << "working in...";
	}
};

class SinhVien : public Person {
public:
	void eat()
	{
		cout << "Working in the university";
	}
};

int main() {
	SinhVien sv;
	sv.eat(); // output: Working in the university
}
```