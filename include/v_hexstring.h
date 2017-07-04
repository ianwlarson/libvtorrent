
#ifndef V_HEXSTRING_H
#define V_HEXSTRING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdint.h>
    
int v_hexstring_to_bytearray(const char *hexstr, uint8_t *buf_out, size_t buflen);


#ifdef __cplusplus
}
#endif

#endif /* V_HEXSTRING_H */

