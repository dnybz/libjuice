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

#include "md5.h"

#if USE_NETTLE
#include <nettle/md5.h>
#else
#include "picohash.h"
#endif

void hash_md5(const void *message, size_t size, void *digest) {
#if USE_NETTLE
	struct md5_ctx ctx;
	md5_init(&ctx);
	md5_update(&ctx, size, message);
	md5_digest(&ctx, HASH_MD5_SIZE, digest);
#else
	picohash_ctx_t ctx;
	picohash_init_md5(&ctx);
	picohash_update(&ctx, message, size);
	picohash_final(&ctx, digest);
#endif
}
