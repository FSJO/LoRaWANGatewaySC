/**
 * Base64 encoding and decoding of strings. Uses '+' for 62, '/' for 63, '=' for padding
 */

#ifndef __Base64__
#define __Base64__

class Base64 {
	public:
	/* binary_to_base64:
	 *   Description:
	 *     Converts a single byte from a binary value to the corresponding base64 character
	 *   Parameters:
	 *     v - Byte to convert
	 *   Returns:
	 *     ascii code of base64 character. If byte is >= 64, then there is not corresponding base64 character
	 *     and 255 is returned
	 */
	static unsigned char from_binary(unsigned char v);

	/* base64_to_binary:
	 *   Description:
	 *     Converts a single byte from a base64 character to the corresponding binary value
	 *   Parameters:
	 *     c - Base64 character (as ascii code)
	 *   Returns:
	 *     6-bit binary value
	 */
	static unsigned char to_binary(unsigned char c);

	/* encode_base64_length:
	 *   Description:
	 *     Calculates length of base64 string needed for a given number of binary bytes
	 *   Parameters:
	 *     input_length - Amount of binary data in bytes
	 *   Returns:
	 *     Number of base64 characters needed to encode input_length bytes of binary data
	 */
	static unsigned int encode_length(unsigned int input_length);

	/* decode_base64_length:
	 *   Description:
	 *     Calculates number of bytes of binary data in a base64 string
	 *   Parameters:
	 *     input - Base64-encoded null-terminated string
	 *   Returns:
	 *     Number of bytes of binary data in input
	 */
	static unsigned int decode_length(unsigned char input[]);

	/* encode_base64:
	 *   Description:
	 *     Converts an array of bytes to a base64 null-terminated string
	 *   Parameters:
	 *     input - Pointer to input data
	 *     input_length - Number of bytes to read from input pointer
	 *     output - Pointer to output string. Null terminator will be added automatically
	 *   Returns:
	 *     Length of encoded string in bytes (not including null terminator)
	 */
	static unsigned int encode(unsigned char input[], unsigned int input_length, unsigned char output[]);

	/* decode_base64:
	 *   Description:
	 *     Converts a base64 null-terminated string to an array of bytes
	 *   Parameters:
	 *     input - Pointer to input string
	 *     output - Pointer to output array
	 *   Returns:
	 *     Number of bytes in the decoded binary
	 */
	static unsigned int decode(unsigned char input[], unsigned char output[]);

};

#endif // ifndef