/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "v_hexstring.h"

static void test_empty_string(void **state)
{
    (void) state; /* unused */

    const char a[] = "";
    
    uint8_t buf[10] = {0};
    size_t buflen = 10;
    
    size_t written = v_hexstring_to_bytearray(a, buf, buflen);
    
    assert_int_equal(written, 0);
}

static void test_valid_string00(void **state)
{
	(void) state; /* unused */

	const char a[] = "ab";

	uint8_t buf[10] = {0};
	uint8_t exp_buf[] = { 0xab };
	size_t buflen = 10;

	size_t written = v_hexstring_to_bytearray(a, buf, buflen);

	assert_int_equal(written, 1);
	assert_memory_equal(buf, exp_buf, sizeof(exp_buf));
}

static void test_valid_string01(void **state)
{
	(void) state; /* unused */

	const char a[] = "abef0c8796ccee";
	
	uint8_t exp_buf[] = {0xab, 0xef, 0x0c, 0x87, 0x96, 0xcc, 0xee};
	
	uint8_t buf[10] = {0};
	size_t buflen = 10;
	
	size_t written = v_hexstring_to_bytearray(a, buf, buflen);
	
	assert_int_equal(written, 7);
	assert_memory_equal(buf, exp_buf, sizeof(exp_buf));
}



/* Invalid characters */
static void test_invalid_string00(void **state)
{
	(void) state; /* unused */

	const char a[] = "ag";

	uint8_t buf[10] = {0};
	size_t buflen = 10;

	size_t written = v_hexstring_to_bytearray(a, buf, buflen);

	assert_int_equal(written, 0);
}

/* Invalid string length */
static void test_invalid_string01(void **state)
{
    (void) state; /* unused */
    
    const char a[] = "afe";
    
    uint8_t buf[10] = {0};
    size_t buflen = 10;
    
    size_t written = v_hexstring_to_bytearray(a, buf, buflen);
    
    assert_int_equal(written, 0);
}

/* Output buffer not large enough */
static void test_invalid_arguments00(void **state)
{
    (void) state; /* unused */
    
    const char a[] = "af0234";
    
    uint8_t buf[1] = {0};
    size_t buflen = 1;
    
    size_t written = v_hexstring_to_bytearray(a, buf, buflen);
    
    assert_int_equal(written, 0);
}

/* Null string */
static void test_invalid_arguments01(void **state)
{
    (void) state; /* unused */
    
    uint8_t buf[1] = {0};
    size_t buflen = 1;
    
    size_t written = v_hexstring_to_bytearray(NULL, buf, buflen);
    
    assert_int_equal(written, 0);
}

/* Null output buffer */
static void test_invalid_arguments02(void **state)
{
    (void) state; /* unused */
    
    const char a[] = "af0234";
    
    size_t buflen = 1;
    
    size_t written = v_hexstring_to_bytearray(a, NULL, buflen);
    
    assert_int_equal(written, 0);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_empty_string),
        cmocka_unit_test(test_valid_string00),
        cmocka_unit_test(test_valid_string01),
        cmocka_unit_test(test_invalid_string00),
        cmocka_unit_test(test_invalid_string01),
        cmocka_unit_test(test_invalid_arguments00),
        cmocka_unit_test(test_invalid_arguments01),
        cmocka_unit_test(test_invalid_arguments02),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
