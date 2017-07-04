#include <stdlib.h>

#include "vtorrent.h"

v_error create_vacuum_context(vac_context **ctxt)
{
    if (ctxt == NULL) {
        return E_NULLPTR;
    }

    vac_context *l_ctxt = malloc(sizeof(*l_ctxt));
    
    l_ctxt->n_active = 0;
    l_ctxt->n_total = 0;
    
    *ctxt = l_ctxt;
    
    return E_SUCCESS;
}

v_error delete_vacuum_context(vac_context **ctxt)
{
    if (ctxt == NULL || *ctxt == NULL) {
        return E_NULLPTR;
    }
    
    vac_context *l_ctxt = *ctxt;
    *ctxt = NULL;
    
    free(l_ctxt);
    
    return E_SUCCESS;
}

v_error add_magnet_uri(vac_context *ctxt, const char *str)
{
    if (ctxt == NULL || str == NULL) {
        return E_NULLPTR;
    }
    
    
    return E_SUCCESS;
}
