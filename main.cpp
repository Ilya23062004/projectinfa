#include <iostream>
#include "dbwork.h"

#include <sstream>

using namespace std;

DbHelper dbHelper;

void readingExistingDb(){
    cout << "reading exiting db " << endl;

    dbHelper =  DbHelper("dbV2.txt", 0);
    dbHelper.readDb();
    dbHelper.printDbData();
}

void addNewRows(){
    cout << endl << "adding new rows " << endl;

    vector <DataHolder> newRow;
    vector < vector < DataHolder > > newRows;

    newRow.push_back(DataHolder("fio", "Lev SA" , "string"));
    newRow.push_back(DataHolder("age", "99" , "string"));
    newRow.push_back(DataHolder("class", "7A" , "string"));

    newRows.push_back(newRow);
    newRow.clear();

    newRow.push_back(DataHolder("fio", "Max FR" , "string"));
    newRow.push_back(DataHolder("age", "33" , "string"));
    newRow.push_back(DataHolder("class", "9A" , "string"));

    newRows.push_back(newRow);
    newRow.clear();

    dbHelper.addRows(newRows);
    dbHelper.printDbData();
}

void deleteRow(){
    cout << endl << "deleting rows " << endl;

    dbHelper.deleteRow(4);
    dbHelper.setCellNewData(3, "avg mark", "5.5");
    dbHelper.printDbData();
}

void addNewColunm(){
    cout << endl << "add new colunm " << endl;

    dbHelper.addColunm("avg mark");
    dbHelper.printDbData();
}


int main() {

    readingExistingDb();

    dbHelper.fixIds();

}

