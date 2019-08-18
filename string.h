#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct wstring 
{
	uint8_t* data;
	uint8_t length;
	uint8_t how_much;
}str_t;

str_t* string_create(uint8_t length)
{
	str_t* string = (str_t*)malloc(sizeof(str_t));
	string->data = (uint8_t*)malloc(length);             // (*string).data = ...
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

size_t strln(const char* string)
{
	size_t length = 0;

	while (*string != '\0')
	{
		length++;
		string++;
	}

	return length;
}

void print_string(str_t* string, FILE* file)
{
	fwrite(string->data, sizeof(uint8_t), string->length, file);
}

str_t* string_dup(const char* str)
{
	str_t* string = string_create((uint8_t)strlen(str));
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
	str_t* space = string_dup(" ");
	str_t* string = string_create(left->length + right->length + space->length);
	memcpy(string->data, left->data, left->length);
	memcpy(string->data + left->length, space->data, space->length);
	memcpy(string->data + left->length + space->length, right->data, right->length);
	string->how_much = string->length;

	return string;
}
