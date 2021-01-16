/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V01                                                               */
/* Date      : 16 January 2021                                                   */
/*********************************************************************************/
#ifndef CSVREADER_H
#define CSVREADER_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void emptyArray(string arr[], int int_size);
/// <summary>
/// 
/// </summary>
class CSVReader
{

private:
	string fileName;
	char COL_delimeter;
	char ROW_delimeter;
	int numberOfCol;
	int numberOfRow;
	ifstream fin;
	bool foundRecord = false;
	void gotoBeginning(void);
public:

	/// <summary>
	/// Initializes a new instance of the <see cref="CSVReader"/> class.
	/// </summary>
	/// <param name="string_fileWithExten">File name with extention.</param>
	CSVReader(string string_fileWithExten);

	/// <summary>
	/// Sets the file name.
	/// </summary>
	/// <param name="string_fileWithExten">File name with extention.</param>
	void setfileName(string string_fileWithExten);
	/// <summary>
	/// Sets the row delimeter.
	/// </summary>
	/// <param name="char_rowDelimeter">The character describe row delimeter.</param>
	void setRowDelimeter(char char_rowDelimeter);

	/// <summary>
	/// Sets the col delimeter.
	/// </summary>
	/// <param name="char_colDelimeter">The character describe col delimeter.</param>
	void setColDelimeter(char char_colDelimeter);

	/// <summary>
	/// Gets the file name.
	/// </summary>
	/// <returns>file name.</returns>
	string getfileName(void);

	/// <summary>
	/// Prints the CSV file content.
	/// </summary>
	void printCSV(void);
	/// <summary>
	/// Gets the number of columns in csv file.
	/// </summary>
	/// <returns>number of columns.</returns>
	int getNumOfCols(void);
	/// <summary>
	/// Gets the number of rows in csv file.
	/// </summary>
	/// <returns>number of rows.</returns>
	int getNumOfRows(void);

	/// <summary>
	/// Get specific column.
	/// </summary>
	/// <param name="numOfCol">The number of this column.</param>
	/// <param name="string_resultArr">set column on this array, each cell in index.</param>
	void getCol(int numOfCol, string string_resultArr[]);
	/// <summary>
	/// Get specific row.
	/// </summary>
	/// <param name="numOfRow">The number of this row.</param>
	/// <param name="string_resultArr">set row on this array, each cell in index.</param>
	void getRow(int numOfRow, string string_resultArr[]);

	/// <summary>
	/// Closes the CSV file.
	/// </summary>
	void closeFile(void);
	/// <summary>
	/// Finalizes an instance of the <see cref="CSVReader"/> class.
	/// </summary>
	~CSVReader();


};
#endif