#include <string>
#include <iostream>


TEST (string, length) {
  std::string str="hello, world!";
  ASSERT_EQ(13, str.length());
}

TEST (string, empty) {
  std::string str="";
  ASSERT_EQ(true, str.empty());
}

TEST (string, clear) {
  std::string str="hello, world!";
  ASSERT_EQ(13, str.length());
  str.clear();
  ASSERT_EQ(0, str.length());
  ASSERT_EQ(true, str.empty());
}

TEST (string, insert) {
  std::string str="hello, world!";
  std::string str2="my ";
  str.insert(7, str2);
  ASSERT_EQ(16, str.length());
  ASSERT_EQ("hello, my world!", str);
}

TEST (string, copy) {
  char StrAdd[20];
  std::string str="hello, world!";
  std::size_t length = str.copy(StrAdd,6,7);
  ASSERT_EQ("world!", std::string(StrAdd));
}

TEST (string, compare) {
  std::string str="hello, world!";
  std::string str2="hello, my world!";
  std::string str3="hello, world!";
  ASSERT_EQ(0, str.compare(str3));
  ASSERT_EQ(0, str.compare(7,5,str2,10,5));
}

TEST (string, swap){
  std::string str="hello, world!";
  std::string str2="my name is melody";
  str.swap(str2);
  ASSERT_EQ("my name is melody", str);
  ASSERT_EQ("hello, world!", str2);
}

TEST (string, find){
  std::string str="hello, world!";
  std::string str2="world";
  std::size_t foundWorld = str.find(str2);
  std::size_t foundHello = str.find("hello");
  str.replace(str.find(str2),str2.length(),"monkey");
  ASSERT_EQ(7, foundWorld);
  ASSERT_EQ(0, foundHello);
  ASSERT_EQ("hello, monkey!", str);
}
