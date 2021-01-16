#include "CSVReader.h"
CSVReader:: CSVReader(string string_fileWithExten)
{
	fileName = string_fileWithExten;
	fin.open(string_fileWithExten);
	numberOfRow = 0;
	numberOfCol = 0;
	COL_delimeter = ',';
	ROW_delimeter = '\n';
}
void CSVReader::gotoBeginning(void)
{
	/* clear eof flag*/
	fin.clear();
	/*goto start position*/
	fin.seekg(0);
}
void CSVReader::setfileName(string string_fileWithExten)
{
	fileName = string_fileWithExten;
}
void CSVReader::setRowDelimeter(char char_rowDelimeter)
{
	ROW_delimeter = char_rowDelimeter;
}
void CSVReader::setColDelimeter(char char_colDelimeter)
{
	COL_delimeter = char_colDelimeter;
}
string CSVReader::getfileName(void)
{
	return fileName;
}
void CSVReader::printCSV(void)
{
	gotoBeginning();
	char LOC_char = {};
	while (!fin.eof())
	{
		fin.get(LOC_char);
		cout << LOC_char;
	}

}
int CSVReader::getNumOfCols(void)
{
	gotoBeginning();
	int LOC_delimeterCounter = 0, LOC_lineLength = 0;
	string LOC_line;
	while (!fin.eof())
	{
		getline(fin, LOC_line, ROW_delimeter);
		break;
	}
	LOC_lineLength = LOC_line.length();
	for (int LOC_counter = 0; LOC_counter < LOC_lineLength; LOC_counter++)
	{
		if (LOC_line[LOC_counter] == COL_delimeter)
			LOC_delimeterCounter++;
	}
	numberOfCol = LOC_delimeterCounter + 1;
	return numberOfCol;
}
int CSVReader::getNumOfRows(void)
{
	gotoBeginning();
	int LOC_Counter = 0, LOC_lineLength = 0;
	char LOC_char = {};
	while (!fin.eof())
	{
		fin.get(LOC_char);
		if (LOC_char == ROW_delimeter)
		{
			LOC_Counter++;
		}
	}

	if (LOC_char == ROW_delimeter)
		LOC_Counter--;
	numberOfRow = LOC_Counter;
	return numberOfRow;
}
void CSVReader::getCol(int numOfCol, string string_resultArr[])
{
	emptyArray(string_resultArr, getNumOfRows());
	gotoBeginning();
	char LOC_char = {};
	// COL 2 ==> ( 1 OF , ) BEFORE 
	int LOC_numOfBeforeDelimeter = 0, LOC_nowDelimeterCounter = 0, LOC_arrIndex = 0;
	LOC_numOfBeforeDelimeter = numOfCol - 1;
	while (!fin.eof() && LOC_numOfBeforeDelimeter != 0)
	{
		fin.get(LOC_char);
		if (LOC_char == COL_delimeter)
		{
			LOC_nowDelimeterCounter++;
			if (LOC_numOfBeforeDelimeter == LOC_nowDelimeterCounter)
			{
				foundRecord = true;
			}
			else
			{
				//LOC_nowDelimeterCounter++;
			}
		}
		while (foundRecord)
		{

			fin.get(LOC_char);

			if (LOC_char == COL_delimeter || LOC_char == ROW_delimeter)
			{
				foundRecord = false;
			}
			else
			{

				string_resultArr[LOC_arrIndex] += LOC_char;
			}
		}

		if (LOC_char == ROW_delimeter)
		{
			LOC_nowDelimeterCounter = 0;
			LOC_arrIndex++;
		}

	}
	LOC_nowDelimeterCounter = 0;
	LOC_arrIndex = 0;
	if (LOC_numOfBeforeDelimeter == 0)
	{
		while (!fin.eof()) {
			if (LOC_nowDelimeterCounter == 0)
			{
				fin.get(LOC_char);
				if (LOC_char == COL_delimeter) {
					LOC_nowDelimeterCounter++;
				}
				else
				{
					string_resultArr[LOC_arrIndex] += LOC_char;
				}

			}
			else
			{
				fin.get(LOC_char);
				if (LOC_char == ROW_delimeter)
				{
					LOC_nowDelimeterCounter = 0;
					LOC_arrIndex++;
				}
			}

		}
	}
	foundRecord = false;
}
void CSVReader::getRow(int numOfRow, string string_resultArr[])
{
	emptyArray(string_resultArr, getNumOfCols());
	gotoBeginning();
	char LOC_char = {};
	int LOC_numOfBeforeDelimeter = 0, LOC_nowDelimeterCounter = 0, LOC_arrIndex = 0;
	if (numOfRow == 1)
	{
		while (!fin.eof())
		{
			fin.get(LOC_char);
			if (LOC_char == COL_delimeter)
			{
				LOC_arrIndex++;
			}
			else
			{
				string_resultArr[LOC_arrIndex] += LOC_char;
			}
			if (LOC_char == ROW_delimeter)
			{
				break;
			}
		}


	}
	else
	{
		LOC_numOfBeforeDelimeter = numOfRow - 1;
		while (!fin.eof())
		{
			fin.get(LOC_char);
			if (LOC_char == ROW_delimeter)
			{
				fin.get(LOC_char); // remove \n
				LOC_nowDelimeterCounter++;
			}
			if (LOC_nowDelimeterCounter == LOC_numOfBeforeDelimeter)
			{
				if (LOC_char == COL_delimeter || LOC_char == ROW_delimeter) /* to remove ,	*/
				{
					if (LOC_char == COL_delimeter)
						LOC_arrIndex++;
					fin.get(LOC_char);
				}
				string_resultArr[LOC_arrIndex] += LOC_char;

			}
		}

	}
}
void CSVReader::closeFile(void)
{
	fin.close();
}
CSVReader :: ~CSVReader(void)
{
	fin.close();
}


void emptyArray(string arr[], int int_size)
{
	for (int i = 0; i < int_size; i++)
		arr[i] = "";
}