#ifndef _INCLUDE_R_LINE_H_
#define _INCLUDE_R_LINE_H_

#include <r_types.h>
#include <r_cons.h>
#include <r_util.h>

#define R_LINE_BUFSIZE 4096
#define R_LINE_HISTSIZE 256

typedef struct r_line_hist_t {
	char **data;
	int size;
	int index;
	int top;
	int autosave;
} RLineHistory;

typedef struct r_line_buffer_t {
	char data[R_LINE_BUFSIZE];
	int index;
	int length;
} RLineBuffer;

typedef struct r_line_t RLine; // forward declaration

typedef int (*RLineCallback)(RLine *line);

typedef struct r_line_comp_t {
	int argc;
	const char **argv;
	RLineCallback run;
} RLineCompletion;

struct r_line_t {
	RLineCompletion completion;
	RLineHistory history;
	RLineBuffer buffer;
	int echo;
	int has_echo;
	char *prompt;
	char *clipboard;
	int disable;
	void *user;
}; /* RLine */

#ifdef R_API

R_API RLine *r_line_new();
R_API RLine *r_line_singleton();
R_API void r_line_free();
R_API char *r_line_get_prompt ();
R_API void r_line_set_prompt(const char *prompt);

R_API int r_line_hist_load(const char *file);
R_API char *r_line_readline();
/* label ?! */
R_API int r_line_hist_add(const char *line);
R_API int r_line_hist_save(const char *file);
R_API int r_line_hist_label(const char *label, void (*cb)(const char*));
R_API void r_line_label_show();

#endif
#endif
