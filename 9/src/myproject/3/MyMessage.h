void message(std::ostream &stream, const char *string) {}

template<typename Arg, typename... Args>
void message(std::ostream &stream, const char *string, Arg &&arg, Args &&... args) {

    while (*string) {
        if (*string == '%') {
            string++;
            break;
        }
        stream << *string;
        string++;
    }
    stream << arg;
    message(stream, string, args...);
}
