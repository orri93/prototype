#include "format.h"

static char* nfb = new char[32];

static size_t fd_format_quote(char* buffer, fd_rdd_data* data, int at);

size_t fd_format_quotes(char* buffer, fd_rdd_data* data) {
  for (int i = 0; i < data->count; i++) {
    size_t fl = fd_format_quote(buffer, data, i);
    buffer += fl;
  }
}

size_t fd_format_quote(char* buffer, fd_rdd_data* data, int at) {
  size_t len = strlen(data->quotes[at].symbol);
  strcpy(buffer, data->quotes[at].symbol);
  buffer += len;
  *buffer = ':';
  buffer++;
  len++;

  memset(nfb, '\0', 30);
  dtostrf(data->quotes[at].price, 9, 4, nfb);
  size_t nlen = strlen(nfb);
  strcpy(buffer, nfb);
  buffer += nlen;
  len += nlen;
  *buffer = ';';
  buffer++;
  len++;

  return len;
}
