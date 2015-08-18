#include "MyString.h"
#include <assert.h>

using namespace std;

int main()
{
	{
		// MyString(const char* s);
		MyString s("C-style\0string");
		std::cout << s << '\n'; // "C-style"
	}

	{
	    // MyString(char* const s, size_t len)
		MyString s("C-style string", 7);
	    std::cout << s << '\n'; // "C-style"
    }

	// const char& back() const;
    {
		MyString const c("Exemplary");
	    char const& back = c.back();
	    std::cout << back << '\n'; // 'y'
    }

	// const char& front() const;
    {
		MyString const c("Exemplary");
	    char const& f = c.front();
	    std::cout << &f << '\n'; // "Exemplary"
    }

	{
		MyString s("message"); // for capacity

		s = "abc";
		s.at(2) = 'x'; // ok
		std::cout << s << '\n';

		std::cout << "string size = " << s.size() << '\n';
		std::cout << "string capacity = " << s.capacity() << '\n';

		try {
			// throw, even if capacity allowed to access element
			s.at(3) = 'x';
		}
		catch (std::out_of_range const& exc) {
			std::cout << exc.what() << '\n';
		}
	}

	{
		// bool empty() const;
		MyString s;
		boolalpha(cout);
		std::cout << "s.empty():" << s.empty() << "\t s:'" << s << "'\n";

		s = "Exemplar";
		std::cout << "s.empty():" << s.empty() << "\t s:'" << s << "'\n";

		s = "";
		std::cout << "s.empty():" << s.empty() << "\t s:'" << s << "'\n";
	}

	// void clear();
	{
		MyString s{ "Exemplar" };

		s.clear();
		assert(s.size() == 0);
	}

	// MyString& erase(size_t index, size_t count);
	{
		MyString s = "This is an example";
		std::cout << s << '\n';

		s.erase(0, 5); // Erase "This "
		std::cout << s << '\n';
	}

	// void resize(size_t count);
	{
		const unsigned  desired_length(8);
		MyString     long_string("Where is the end?");
		//long_string.erase(5, 8);
		//printf("%s\n", long_string);
		std::cout << "Before: \"" << long_string << "\"\n";
		long_string.resize(desired_length);
		std::cout << "After: \"" << long_string << "\"\n";
	}

	// char *copy(char* dest,	size_t count) const;
	{
		MyString foo("quuuux");
		char bar[7];
		foo.copy(bar, 4);
		bar[6] = '\0';
		std::cout << bar << '\n';
	}

	// friend MyString operator +(const MyString& lhs, const char* rhs);
	{
		MyString s1 = "Hello";
		MyString s2 = "world";
		std::cout << s1 + ' ' + s2 + "!\n";
	}

	getchar();
	return 0;
}