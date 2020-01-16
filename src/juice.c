/**
 * Copyright (c) 2020 Paul-Louis Ageneau
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "juice.h"
#include "agent.h"

juice_agent_t *juice_create(const juice_config_t *config) {
	if (!config)
		return NULL;
	return agent_create(config);
}

void juice_destroy(juice_agent_t *agent) {
	if (agent)
		agent_destroy(agent);
}

int juice_gather_candidates(juice_agent_t *agent) {
	if (!agent)
		return -1;
	return agent_gather_candidates(agent);
}

int juice_get_local_description(juice_agent_t *agent, char *buffer, size_t size) {
	if (!agent || (!buffer && size))
		return -1;
	return agent_get_local_description(agent, buffer, size);
}

int juice_set_remote_description(juice_agent_t *agent, const char *sdp) {
	if (!agent || !sdp)
		return -1;
	return agent_set_remote_description(agent, sdp);
}

int juice_add_remote_candidate(juice_agent_t *agent, const char *sdp) {
	if (!agent && !sdp)
		return -1;
	return agent_add_remote_candidate(agent, sdp);
}

int juice_send(juice_agent_t *agent, const char *data, size_t size) {
	if (!agent && (!data && size))
		return -1;
	return agent_send(agent, data, size);
}

const char *juice_state_to_string(juice_state_t state) {
	switch (state) {
	case JUICE_STATE_DISCONNECTED:
		return "disconnected";
	case JUICE_STATE_GATHERING:
		return "gathering";
	case JUICE_STATE_CONNECTING:
		return "connecting";
	case JUICE_STATE_CONNECTED:
		return "connected";
	case JUICE_STATE_COMPLETED:
		return "completed";
	case JUICE_STATE_FAILED:
		return "failed";
	default:
		return "unknown";
	}
}
