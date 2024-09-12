{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.gcc         # Compilador C++
    pkgs.cmake       # Ferramenta de build
    pkgs.gdb         # Debugger
    pkgs.clang-tools # Ferramentas de análise de código
  ];

  vscodeExtensions = with pkgs.vscode-extensions; [
    ms-vscode.cpptools          # Suporte a C/C++ com IntelliSense e Debugging
    ms-vscode.cmake-tools       # Ferramenta para integração com CMake
  ];

   shellHook = ''
    echo "Ambiente de desenvolvimento C++ com VS Code pronto!"
  '';
}