
#ifndef V_ERROR_H
#define V_ERROR_H

typedef enum {
    E_SUCCESS = 0,
    E_NOMEMORY,
    E_NULLPTR,
    E_BAD_CONTEXT,
    E_INVALID_ARGUMENT,
    E_INVALID_OUTPUT,
	ERROR_COUNT,
} v_error;

#endif // V_ERROR_H

