/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <max.h>

int main(void)
{
	printf("Hello World! %s\n", CONFIG_BOARD);

	int a = 10;
	int b = 20;
	int ret = max(a, b);

	printf("Max value: %d\n", ret);
	return 0;
}
