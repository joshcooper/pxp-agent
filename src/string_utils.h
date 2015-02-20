#ifndef SRC_STRINGUTILS_H_
#define SRC_STRINGUTILS_H_

#include <string>
#include <vector>

namespace CthunAgent {
namespace StringUtils {

/// Return the "s" string in case of more than one things,
/// an empty string otherwise.
std::string plural(int num_of_things);

template<typename T>
std::string plural(std::vector<T> things);

/// Adds the specified expiry_minutes to the current time and returns
/// the related date time string in UTC format.
/// Returns an empty string in case it fails to allocate the buffer.
std::string getExpiryDatetime(int expiry_minutes = 1);

/// Erases the current line on stdout, places the cursor at the
/// beginning of it, and displays a progress message.
void displayProgress(double percent, int len,
                     std::string status = "in progress");

/// Return the current time in ISO8601 format
std::string getISO8601Time(unsigned int modifier_in_seconds = 0);

/// Returns the length of the string txt, in terms of bytes, when
/// encoded as UTF-8
int getLengthOfUTF8String(std::string txt);

}  // namespace StringUtils
}  // namespace CthunAgent

#endif  // SRC_STRINGUTILS_H_