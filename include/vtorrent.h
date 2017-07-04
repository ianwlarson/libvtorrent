#ifndef VTORRENT_H
#define VTORRENT_H

#include <stdlib.h>
#include <stdint.h>

#include "v_error.h"

typedef struct {
    size_t n_active; // Number of active torrents.
    size_t n_total; // Total number of torrents managed by this context.
} vac_context;

v_error create_vacuum_context(vac_context **ctxt);

v_error add_magnet_uri(vac_context *ctxt, const char *str);

#endif // VTORRENT_H
