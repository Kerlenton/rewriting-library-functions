#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
	uint8_t* data;
	uint8_t length;
	uint8_t how_much;
}str_t;

size_t strlen(const uint8_t* string)
{
	size_t count = 0;

	while (*string != '\0')
	{
		count++;
		string++;
	}
}

str_t* string_create(uint8_t length)
{
	str_t* string = (str_t*) malloc(sizeof(str_t));         // (*string).data = ...
	string->data = (uint8_t*) malloc(length);
	string->length = length;
	string->how_much = 0;

	return string;
}

void string_free(str_t* string)
{
	free(string->data);
	free(string);
}

uint8_t string_length(str_t* string)
{
	return string->length;
}

void print_string(str_t* string, FILE* file)
{
	fwrite(string->data, sizeof(uint8_t), string->length, file);
}

str_t* strdup(const uint8_t* str)
{
	str_t* string = string_create((uint8_t) strlen(str));
	memcpy(string->data, str, string->length);
	string->how_much = string->length;

	return string;
}

str_t* concat(str_t* left, str_t* right)
{
	str_t* string = string_create(left->length + right->length);
	memcpy(string->data, left->data, left->length);
	memcpy(string->data + left->length, right->data, right->length);
	string->how_much = string->length;

	return string;
}

str_t* append(str_t* left, str_t* right)
{
	str_t* space = strdup(" ");
	str_t* string = string_create(left->length + right->length + space->length);
	memcpy(string->data, left->data, left->length);
	memcpy(string->data + left->length, space->data, space->length);
	memcpy(string->data + left->length + space->length, right->data, right->length);
	string->how_much = string->length;

	return string;
}}
