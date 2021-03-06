/****************************************************************************
 *
 * Copyright 2019 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/

/***************************************************************************
 * Included Files
 ***************************************************************************/

#include <stdio.h>
#include <debug.h>
#include <sched.h>
#include <tinyara/binary_manager.h>
#include <binary_manager/binary_manager.h>
#include "binary_manager_internal.h"

int binary_manager_notify_binary_started(void)
{
	int ret;
	binmgr_request_t request_msg;

	request_msg.cmd = BINMGR_NOTIFY_STARTED;
	request_msg.requester_pid = getpid();
	snprintf(request_msg.data.bin_name, BIN_NAME_MAX, "%s", BINMGR_REQUEST_MQ);

	ret = binary_manager_send_request(&request_msg);
	if (ret < 0) {
		bmdbg("Failed to send request msg %d\n", ret);
		return BINMGR_COMMUNICATION_FAIL;
	}

	return BINMGR_OK;
}
