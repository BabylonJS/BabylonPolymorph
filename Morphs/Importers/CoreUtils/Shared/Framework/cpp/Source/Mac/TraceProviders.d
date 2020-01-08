provider Bigpark
{
    probe trace_stack();
    probe trace_info(int, char*);
    probe print_header();
    probe trace_mark(char*, char*, long long, int, int32_t, char*, char*); //EventType, EventName, Time Offset (ns), Value, FunctionName, FileName, LineNum
    probe trace_measurement_char(char*, char*, long long, char*, int32_t, char*, char*); //EventType, EventName, Time Offset (ns), Value, FunctionName, FileName, LineNum
    probe trace_timespan(char*, char*, long long, long long, int32_t, char*, char*); //EventType, EventName, Time Offset (ns), Start Time (ns), FunctionName, FileName, LineNum
    probe trace_measurement_double(char*, char*, long long, int, int, int32_t, char*, char*);
};
