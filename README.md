# Cplusplus

Useful References:

--------------Arrays---------------:
```
int a[5];
int b[5] = {11, 45, 62, 70, 88};

type name[size1][size2]...[sizeN];
int x[3][4];


int[ ][ ] sample = { {1, 2, 3}, {4, 5, 6} }; 
```
--------------Pointers---------------:
```
int var = 50;
int  *p;
p = &var;

cout << var << endl;
// Outputs 50 (the value of var)

cout << p << endl;
// Outputs 0x29fee8 (var's memory location)

cout << *p << endl;
/* Outputs 50 (the value of the variable
 stored in the pointer p) */
 
Dereferencing:
x = x + 4;
x = *p + 4;
*p = *p + 4;
```
--------------Dynamic Memory---------------:

The stack: All of your local variables take up memory from the stack.

*The heap: Unused program memory that can be used when the program runs to dynamically allocate the memory.
```
new int;

int *p = new int; // request memory
*p = 5; // store value

cout << *p << endl; // use value

delete p; // free up the memory

int *p = NULL; // Pointer initialized with null
p = new int[20]; // Request memory
delete [] p; // Delete array pointed to by p
```
The sizeof operator can be used to get a variable or data type's size, in bytes.
sizeof (data type)

--------------Loops---------------:

"Enhanced for loop" aka "for each"
```
for ( auto foo : bar )
{
  // something
}

for (auto p = c.begin(); p != c.end(); p++) {
// do something with *p
}
```
*Object oriented programming: identity, attributes, behavior.

--------------Encapsulation---------------:

"The packing of data and methods into a single component."
'In object orientation, encapsulation means more than simply combining attributes and behavior together within a class; it also means restricting access to the inner workings of that class.'

For example, if we take a BankAccount class, we do not want some other part of the program to reach in and change the balance of any object, without going through the deposit() or withdraw() behaviors.
We should hide that attribute, control access to it, so it is accessible only by the object itself.
This way, the balance cannot be directly changed from outside of the object and is accessible only using its methods.
This is also known as "black boxing", which refers to closing the inner working zones of the object, except of the pieces that we want to make public.
This allows us to change attributes and implementation of methods without altering the overall program. For example, we can come back later and change the data type of the balance attribute.

In summary the benefits of encapsulation are:
- Control the way data is accessed or modified.
- Code is more flexible and easy to change with new requirements.
- Change one part of code without affecting other part of code.
```
#include <iostream>
#include <string>
using namespace std;

class myClass {
  public:
    void setName(string x) {
      name = x;
    }
    string getName() {
      return name;
    }
  private:
    string name;
};

int main() {
  myClass myObj;
  myObj.setName("John");
  cout << myObj.getName();

  return 0;
}

//Outputs "John"
```

--------------Operator Overloading---------------:

"When methods have the same name, but different parameters, it is known as method overloading.
This can be very useful when you need the same method functionality for different types of parameters.
```
class MyClass {
 public:
  int var;
  MyClass() {}
  MyClass(int a)
  : var(a) { }

  MyClass operator+(MyClass &obj) {
   MyClass res;
   res.var= this->var+obj.var;
   return res; 
  }
};

int main() {
  MyClass obj1(12), obj2(55);
  MyClass res = obj1+obj2;

  cout << res.var;
}

//Outputs 67
```

--------------Inheritance-----------

"Inheritance allows us to define a class based on another class. This facilitates greater ease in creating and maintaining an application." 
'The class whose properties are inherited by another class is called the Base class. The class which inherits the properties is called the Derived class.'
```
#include <iostream>
using namespace std;

class Mother
{
 public:
  Mother() {};
  void sayHi() {
   cout << "Hi";
  }
};

class Daughter: public Mother
{
 public:
  Daughter() {};
};

int main() {
  Daughter d;
  d.sayHi();
}
//Outputs "Hi"
```

--------------Polymorphism---------------:

"A call to a member function will cause a different function to be executed depending on the type of object that invokes the function."
'C++ polymorphism means that a call to a member function will cause a different implementation to be executed depending on the type of object that invokes the function.'
Simply, polymorphism means that a single function can have a number of different implementations.
```
class Enemy {
 protected: 
  int attackPower;
 public:
  void setAttackPower(int a){
   attackPower = a;
  }
};

class Ninja: public Enemy {
 public:
  void attack() {
   cout << "Ninja! - "<<attackPower<<endl;
  }
};

class Monster: public Enemy {
 public:
  void attack() {
   cout << "Monster! - "<<attackPower<<endl;
  }
};

int main() {   
 Ninja n;
 Monster m;  
}

Ninja and Monster inherit from Enemy, so all Ninja and Monster objects are Enemy objects. This allows us to do the following:
Enemy *e1 = &n;
Enemy *e2 = &m;

We've now created two pointers of type Enemy, pointing them to the Ninja and Monster objects.

int main() {
  Ninja n;
  Monster m;
  Enemy *e1 = &n;
  Enemy *e2 = &m;

 e1->setAttackPower(20);
 e2->setAttackPower(80);

 n.attack();
 m.attack();
}

/* Output:
Ninja! - 20
Monster! - 80
*/
```
--------------Virtual Functions---------------:

"A function or method whose behavior can be overridden within an inheriting class by a function with the same signature"

```
class Enemy {
 public:
  virtual void attack() {
  }
};

class Ninja: public Enemy {
 public:
  void attack() {
   cout << "Ninja!"<<endl;
  }
};

class Monster: public Enemy {
 public:
  void attack() {
   cout << "Monster!"<<endl;
 }
};

int main() {
  Ninja n;
  Monster m;
  Enemy *e1 = &n;
  Enemy *e2 = &m;

  e1->attack();
  e2->attack();
}

/* Output:
Ninja!
Monster!
*/
```
--------------Class Templates---------------:

"A function or method whose behavior can be overridden within an inheriting class by a function with the same signature"

```
template <class T>
class Pair {
 private:
  T first, second;
 public:
  Pair (T a, T b):
   first(a), second(b){
  }
  T bigger();
};

template <class T>
T Pair<T>::bigger() {
  return (first>second ? first : second);
}

Pair <int> obj(11, 22);
cout << obj.bigger();
// Outputs 22
```
--------------Throwing Exceptions---------------:

"C++ exception handling is built upon three keywords: try, catch, and throw.
throw is used to throw an exception when a problem shows up."

```
int motherAge = 29;
int sonAge = 36;
if (sonAge > motherAge) {
  throw "Wrong age values";
}
```
The code looks at sonAge and motherAge, and throws an exception if sonAge is found to be the greater of the two.
In the throw statement, the operand determines a type for the exception. This can be any expression. The type of the expression's result will determine the type of the exception thrown.


A try block identifies a block of code that will activate specific exceptions. It's followed by one or more catch blocks. The catch keyword represents a block of code that executes when a particular exception is thrown. 
Code that could generate an exception is surrounded with the try/catch block.
You can specify what type of exception you want to catch by the exception declaration that appears in parentheses following the keyword catch.
```
try {
  int motherAge = 29;
  int sonAge = 36;
  if (sonAge > motherAge) {
   throw 99;
  }
} 
catch (int x) {
  cout<<"Wrong age values - Error "<<x;
}

//Outputs "Wrong age values - Error 99"
```
The try block throws the exception, and the catch block then handles it.
The error code 99, which is an integer, appears in the throw statement, so it results in an exception of type int.

--------------Working with Files---------------:


 ofstream: Output file stream that creates and writes information to files.
 
ifstream: Input file stream that reads information from files.

fstream: General file stream, with both ofstream and ifstream capabilities that allow it to create, read, and write information to files.

```
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ofstream MyFile;
  MyFile.open("test.txt");

  MyFile << "Some text! \n";
  MyFile.close();
}
//If doesn't exsits, created!

File Opening Modes:
ios::app - append to end of file
ios::ate - go to end of file on opening
ios::binary - file open in binary mode
ios::in - open file for reading only
ios::out - open file for writing only
ios::trunc - delete the contents of the file if it exists

ofstream outfile;
outfile.open("file.dat", ios::out | ios::trunc ); // combined with bitwise operator (|) OR (is possible)
```
Read only
```
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  string line;
  ifstream MyFile("test.txt");
  while ( getline (MyFile, line) ) {
   cout << line << '\n';
  }
  MyFile.close();
}
```
