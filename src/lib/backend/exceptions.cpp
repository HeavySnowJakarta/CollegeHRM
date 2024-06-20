#include "exceptions.h"
#include <string>

const char* databaseBrokenType2String(DatabaseBrokenType type){
    switch (type) {
    case DatabaseBrokenType::unexpectedString:
        return "Unexpected string. ";
    case DatabaseBrokenType::failedToParse:
        return "Failed to parse the database file. ";
    case DatabaseBrokenType::lostField:
        return "A field of the database is lost. ";
    }
}

DatabaseBrokenException::DatabaseBrokenException(
    DatabaseBrokenType type,
    const char* optionalHint
) : CollegeHRMException(
    (
        std::string(databaseBrokenType2String(type))
            + std::string(optionalHint)
    ).c_str()
){}