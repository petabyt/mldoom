#include <stdio.h>
#include <dryos.h>
#include <module.h>
#include <menu.h>
#include <config.h>
#include <bmp.h>
#include <console.h>
#include <math.h>

int main(char *argv[], int argc);

#include "doom.h"

#include "doomkeys.h"

extern int menu_redraw_blocked;
int running = 0;

void DG_Init() {
    // ???
}

uint32_t DG_GetTicksMs() {
	return get_ms_clock();
}

void DG_SleepMs(uint32_t ms) {
    msleep(ms);
}

void DG_DrawFrame() {
    for (int x = 0; x < DOOMGENERIC_RESX; x++) {
        for (int y = 0; y < DOOMGENERIC_RESY; y++) {
            bmp_putpixel_fast(bmp_vram(), x, y, DG_ScreenBuffer[y * DOOMGENERIC_RESX + x]);
        }
    } 
}

void DG_SetWindowTitle(const char *title) {
	return;
}

void doom_task()
{
    char *argv[] = {"doom"};

	running = 1;
    main(argv, 1);
}

static MENU_SELECT_FUNC(doom_start)
{
    menu_redraw_blocked = 1;
    task_create("doom_task", 0x1e, 0x4000, doom_task, (void*)0);
}

int DG_GetKey(int* pressed, unsigned char* doomKey) {
    return 0;
}

unsigned int doom_keypress(unsigned int key)
{
    if (!running)
    {
        return 1;
    }

    switch (key) {
    case MODULE_KEY_Q:
        break;
    }

    return 0;
}

struct menu_entry doom_menu[] =
{
    {
        .name = "ML doom",
        .select = doom_start,
        .help = "doom on your DSLR",
    },
};

unsigned int doom_init()
{
    menu_add("Games", doom_menu, COUNT(doom_menu));
    return 0;
}

unsigned int doom_deinit()
{
    return 0;
}

MODULE_CBRS_START()
MODULE_CBR(CBR_KEYPRESS, doom_keypress, 0)
MODULE_CBRS_END()

MODULE_INFO_START()
MODULE_INIT(doom_init)
MODULE_DEINIT(doom_deinit)
MODULE_INFO_END()
