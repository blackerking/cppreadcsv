#include "readcsv.h"

///Notwendige Routinen///

std::string passetextan(std::string argstring)
{
    argstring.erase(argstring.begin());
    argstring.erase(argstring.end()-1);
    return argstring;
}



///STORAGE Daten ///

typedef struct {
	std::string value1;
	std::string value2;
	std::string value3;
	std::string value4;
	std::string value5;
} CSV_typ;

std::ostream& operator<< (std::ostream& out, const CSV_typ& d) {
	return
		out << d.value1 << d.value2 << d.value3 << d.value4 << d.value5;
}

std::string readcsv(void) {
	std::ifstream datei1("file.csv");

	if ( datei1.is_open() )
	{
		std::string inhaltzeile;
		std::vector<CSV_typ> content;

		while (getline(datei1,inhaltzeile)) {
			CSV_typ entry;

			std::istringstream is(inhaltzeile);

			if (
				getline(is, entry.value1, ',') &&
				getline(is, entry.value2, ',') &&
				getline(is, entry.value3, ',') &&
                getline(is, entry.value4, ',') &&
				getline(is, entry.value5, ';') )
			{
				content.push_back(entry);
			}
			else {
				std::cerr << "Nicht verstandene Zeile: " << inhaltzeile << std::endl;
				exit(10);
			}
		}
		content.erase(content.begin());                         // Tabellenkopf löschen
        std::string readstring;
        for(int i=0; content.size() > i; i++)
			 {

			     std::string value1 = content[i].value1;
			     std::string value2 = content[i].value2;
			     std::string value3 = content[i].value3;
			     std::string value4 = content[i].value4;
			     std::string value5 = content[i].value5;

                 value1 = passetextan(value1);
				 value2 = passetextan(value2);
                 value3 = passetextan(value3);
                 value4 = passetextan(value4);
                 value5 = passetextan(value5);


			     readstring += value1 + " " + value2 + " " + value3 + " " + value4 + " " + value5;
			     if(content.size() > i) readstring += ",";
			 }
        datei1.close();
        return readstring;
	}

	else
	{
		std::cerr << "\n\nFehler\n\nDatei konnte nicht geoeffnet werden!." << std::endl;
		exit(1);
	}
}
