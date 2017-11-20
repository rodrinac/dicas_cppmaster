#include "sqlite3.h"
#include <SQLiteCpp/SQLiteCpp.h> // SQLite::Database, SQLite::Statement, SQLite::Column
#include <iostream>              // para cout, endl 
#include <fstream>               // para ifstream, ofstream
using namespace std;

namespace usage {
    const string  in = "C:\\Users\\Jose\\C++ Programas\\C++\\Usando a Classe Vector de C++.pdf";
    const string out = "C:\\Users\\Jose\\Desktop\\Vector C++.pdf";

    ifstream  inFile;
    ofstream outFile;

	// Calcula o tamanho do arquivo [em bytes]
    fstream::pos_type calcFileSize(istream &in)
    {
        in.seekg(0, ios_base::end);
        fstream::pos_type size = in.tellg();
        in.seekg(0, ios_base::beg);

        return size;
    }
}

int main(int argc, char *argv[])
{
   // Abre o arquivo em modo binário	
   usage::inFile.open(usage::in, ios_base::binary);
   const fstream::pos_type FILE_SIZE = usage::calcFileSize(usage::inFile);

   char file_data[(int)FILE_SIZE]; // Obtem o conteúdo do arquivo
   usage::inFile.read(file_data, FILE_SIZE);

   cout <<"Arquivo lido!" <<endl; // Abre o conexão com o banco de dados [sqlite ☻]
   SQLite::Database db("C:\\Users\\Jose\\Desktop\\Data.db", SQLITE_OPEN_READWRITE);
   SQLite::Statement qry(db, "INSERT INTO `Arquivos` values('Vector C++', ?)");

   // Envia para a tabela                                     ↓  ↓
   // [estrutura: CREATE TABLE Arquivos(nome VARCHAR(45), arq BLOB)]
   qry.bind(1, (void *)file_data, FILE_SIZE);
   qry.exec();
   cout <<"Arquivo salvo no BD!" <<endl;
   
   // Cria arquivo de saída
   usage::outFile.open(usage::out, ios_base::binary);
   
   // Obtem o conteúdo do campo [BLOB] de arquivo
   SQLite::Column cln = db.execAndGet("SELECT arq FROM Arquivos WHERE nome = 'Vector C++'");
   const void *result = cln.getBlob();

   // Escreve o conteúdo para o arquivo
   usage::outFile.write((const char *)result, FILE_SIZE);
   cout <<"Arquivo escrito, tamanho " <<FILE_SIZE <<" bytes" <<endl;


   return 0; // fecha conexão com o BD, fecha arquivos, etc...
}
