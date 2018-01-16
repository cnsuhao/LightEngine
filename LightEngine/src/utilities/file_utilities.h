#pragma once
#include <iostream>

namespace Light
{
	class FileUtilities
	{
	public:
		static std::string read_file(const char* filepath)
		{
			FILE* file = fopen(filepath, "rt");			// Open the file
			fseek(file, 0, SEEK_END);					// Find the end of the file
			unsigned long length = ftell(file);			// Obtain file length in bytes
			char* data = new char[length + 1];			// Array to hold the payload. +1 for a termination character
			memset(data, 0, length + 1);				// Clear data array
			fseek(file, 0, SEEK_SET);					// Set the seek back to the first byte
			fread(data, 1, length, file);				// Read the file, output to data
			fclose(file);								// Close file

			std::string output(data);
			delete[] data;
			return output;
		}
	};
}