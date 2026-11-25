#include "vmsys.h"
#include "vmtimer.h"
#include "vmstdlib.h"
#include "vmsettings.h"
#include "vmchset.h"
#include "vmpromng.h"
#include "vmio.h"

VMINT my_wallpaper_callback(void* user_data)
{
    return 0;
}

void timer(int a) {
     vm_delete_timer_ex(a);
     vm_exit_app();
}

void mre_set_background_pic(void)
{
    VMWCHAR wallpaper_path[32];
    VMCHAR c_wallpaper_path[32] = "e:\\test.bmp";
    VMINT attributes;

    vm_ascii_to_ucs2(wallpaper_path, sizeof(wallpaper_path), c_wallpaper_path);

    attributes = vm_file_get_attributes(wallpaper_path);

    if (attributes == -1) {

        vm_create_timer_ex(3000, timer);

        return;

    }

    vm_settings_set_wallpaper(VM_SETTINGS_HOME_PAPER, wallpaper_path, my_wallpaper_callback, NULL);

    vm_create_timer_ex(3000, timer);
}

void vm_main(void) {

    vm_pmng_set_bg();
    mre_set_background_pic();

}
