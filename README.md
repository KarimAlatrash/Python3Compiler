# Resources Used
https://tomassetti.me/getting-started-antlr-cpp/
https://tomassetti.me/a-tutorial-on-how-to-write-a-compiler-using-llvm/
https://jakevdp.github.io/PythonDataScienceHandbook/02.01-understanding-data-types.html

# Where I left off
* How will i reduce the scope of python?
* What can I use as my most basic expression? - symbol table/declaration issue
* how do i parse a basic python expression? - parser visitor issue
* To make a Python3DeclarationVisitor I need to make a Python3SymbolFactory. To make a Python3SymbolFactory I need to make a Symbol class with constructors for my different symbols. The symbol class needs to include line, name, ref, offset and state. In the symbol, how do I include the type? We will start with handling declaration of data types numbers, strings.

# Useful Resources
[Info on the Clang AST](https://www.youtube.com/watch?v=VqCkCDFLSsc)