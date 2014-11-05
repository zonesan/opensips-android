/*
 *
 * Copyright (c) 2006 Juha Heinanen
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef PARSE_PRIVACY_H
#define PARSE_PRIVACY_H

#include "../mem/mem.h"
#include "msg_parser.h"


/* bitmap of Privacy header privacy values
 * (http://www.iana.org/assignments/sip-priv-values)
 */
enum privacy_value {
	PRIVACY_USER=1,
	PRIVACY_HEADER=2,
	PRIVACY_SESSION=4,
	PRIVACY_NONE=8,
	PRIVACY_CRITICAL=16,
	PRIVACY_ID=32,
	PRIVACY_HISTORY=64
};


/*
 * casting macro for accessing enumeration of priv-values
 */
#define get_privacy_values(p_msg) \
	((unsigned int)(long)((p_msg)->privacy->parsed))


/*
 * Parse Privacy HF.  Returns 0 on success and -1 on failure.
 */
int parse_privacy(struct sip_msg *msg);


/*
 * Parse a privacy value pointed by start that can be at most max_len long.
 * Returns length of matched privacy value or NULL otherwise.
 */
unsigned int parse_priv_value(char* start, unsigned int max_len,
                              unsigned int* value);


#endif /* PARSE_PRIVACY_H */