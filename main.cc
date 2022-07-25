#include <fstream>
#include <iostream>
#include <vector>

std::vector<char> a;

void get_alpha(int n) {

  std::string alpha("abcdefghijklmnopqrstuvwxyz");

  std::vector<char> tmp;

  for(int i = 0; i < n; i++) {
    a.push_back(alpha.at(i));
  }
}

void gen_make() {

  std::ofstream makefile("makefile");

  for(auto c: a) {
    makefile << c << ':' << '\n' << "\t g++ " << "-o " << c << ".exe " << c << ".cpp\n" << '\n';
    makefile << "\t./" << c << ".exe\n" << '\n';
  }

  makefile.close();
}

void gen_src() {
  
  for(auto c: a) {
    std::string txt;
    txt.push_back(c);
    txt += ".cpp";
    std::ofstream src(txt);
    src << "#include <bits/stdc++.h>\n" << "using namespace std;\n" << "int main() {\n" << "\n" << '\t' << "return 0;\n" << "}";
    src.close();
  }
}

int main(int argc, char** argv) {
  
  if(argc == 1) {
    std::cerr << "No number entered\n";
    return 1;
  }

  get_alpha(atoi(argv[1]));

  gen_make();
  gen_src();

  return 0;
}
