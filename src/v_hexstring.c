/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "v_hexstring.h"

#include <stdlib.h>

static const uint8_t char_xform[256] = {
	['a'] = 0xa,
	['A'] = 0xA,
	['b'] = 0xb,
	['B'] = 0xB,
	['c'] = 0xc,
	['C'] = 0xC,
	['d'] = 0xd,
	['D'] = 0xD,
	['e'] = 0xe,
	['E'] = 0xE,
	['f'] = 0xf,
	['F'] = 0xF,
	['1'] = 0x1,
	['2'] = 0x2,
	['3'] = 0x3,
	['4'] = 0x4,
	['5'] = 0x5,
	['6'] = 0x6,
	['7'] = 0x7,
	['8'] = 0x8,
	['9'] = 0x9,
	['0'] = 0x0,
};

static inline uint8_t char_pair_to_byte(const char pair[2])
{
	uint8_t out = char_xform[(unsigned char)pair[0]];
	out <<= 4;
	out |= char_xform[(unsigned char)pair[1]];

	return out;
}

int v_hexstring_to_bytearray(const char *hexstr, uint8_t *buf_out, size_t buflen)
{
	if (hexstr == NULL || buf_out == NULL) {
		return 0;
	}
	
	size_t slen = strnlen(hexstr, 4096);
	size_t byte_len = slen >> 1;
	
	// TODO: Replace with an IS_ODD function.
	if (slen & 0x1) {
		return 0;
	}
	
	if (buflen < byte_len) {
		return 0;
	}
    
	for (int i = 0; i < slen; ++i) {
		if (hexstr[i] == '0') {
			continue;
		} else if (char_xform[(unsigned char)hexstr[i]] == 0x0) {
			return 0;
		}
	}
	
	for (int i = 0, j = 0; i < byte_len; ++i, j += 2) {
		buf_out[i] = char_pair_to_byte(hexstr + j);
	}
	
	return byte_len;
}
