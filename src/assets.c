/**
 * @file assets.c
 * 
 * @author jevarg
 * @brief Loading/Unloading game assets
 */

#include "assets.h"

char tex_load_flag = 0;
char cycle_load_flag = 0;
char rings_load_flag = 0;
char access_load_flag = 0;
char missile_load_flag = 0;
char keystat_load_flag = 0;
char saucer_load_flag = 0;
char carrier_load_flag = 0;

void
main_menu_load()
{
  PCX_Load("mi_new.pcx", 131, 1);
  PCX_Load("mi_load.pcx", 132, 1);
  PCX_Load("mi_save.pcx", 133, 1);
  PCX_Load("mi_opt.pcx", 134, 1);
  PCX_Load("mi_read.pcx", 135, 1);
  PCX_Load("mi_how.pcx", 136, 1);
  PCX_Load("mi_cre.pcx", 137, 1);
  PCX_Load("mi_demo.pcx", 138, 1);
  PCX_Load("mi_exit.pcx", 139, 1);
  PCX_Load("alogo1.pcx", 140, 1);
}

void
main_menu_unload()
{
  for (int i = 140; i >= 131; i--)
  {
    PCX_Unload(i);
  }
}

void
options_menu_load()
{
  PCX_Load("smi_1.pcx", 131, 1);
  PCX_Load("smi_2.pcx", 132, 1);
  //PCX_Load("smi_3.pcx", 133,1);
  PCX_Load("smi_4.pcx", 133, 1);
  PCX_Load("smi_5.pcx", 135, 1);
  PCX_Load("smi_6.pcx", 136, 1);
  PCX_Load("smi_7.pcx", 137, 1);
  //PCX_Load("smi_8.pcx",138,1);
  //PCX_Load("smi_9.pcx",139,1);
  //PCX_Load("smi_10.pcx",140,1);
  PCX_Load("smi_11.pcx", 141, 1);
  PCX_Load("smi_12.pcx", 142, 1);
  PCX_Load("smi_13.pcx", 143, 1);
}

void
options_menu_unload()
{
  for (int i = 143; i >= 131; i--)
  {
    PCX_Unload(i);
  }
}

void
difflvl_load()
{
  PCX_Load("dfl1.pcx", 131, 1);
  PCX_Load("dfl2.pcx", 132, 1);
  PCX_Load("dfl3.pcx", 133, 1);
  PCX_Load("dfl4.pcx", 134, 1);
}

void
difflvl_unload()
{
  int a;
  for (a = 134; a >= 131; a--)
    PCX_Unload(a);
}

void
doctor_load()
{
  PCX_Load("docmain.pcx", 131, 1);
  PCX_Load("docm1.pcx", 132, 1);
  PCX_Load("docm2.pcx", 133, 1);
  PCX_Load("docm6.pcx", 134, 1);
  PCX_Load("doceye1.pcx", 135, 1);
  PCX_Load("doceye2.pcx", 136, 1);
}

void
doctor_unload()
{
  int a;
  for (a = 136; a >= 131; a--)
    PCX_Unload(a);
}

void
texture_unload()
{
  int a;
  for (a = 0; a < 52; a++)
    PCX_Unload(a);
  tex_load_flag = 0;
}

void
alnum_load()
{
  PCX_Load("alpha.pcx", 145, 0);
}

void
cycle_load()
{
  if (cycle_load_flag)
    return;
  // Load Cycles ///////////////////////
  PCX_Load("hyper1.pcx", 81, 1);
  PCX_Load("hyper2.pcx", 82, 1);
  PCX_Load("hyper3.pcx", 83, 1);
  PCX_Load("hyper4.pcx", 84, 1);
  PCX_Load("hyper5.pcx", 85, 1);
  PCX_Load("hyper6.pcx", 86, 1);
  PCX_Load("hyper7.pcx", 87, 1);
  PCX_Load("hyper8.pcx", 88, 1);
  cycle_load_flag = 1;
}

void
cycle_unload()
{
  int a;
  for (a = 88; a >= 81; a--)
    PCX_Unload(a);
  cycle_load_flag = 0;
}

void
rings_load()
{
  if (rings_load_flag)
    return;
  PCX_Load("rings.pcx", 60, 0);
  Grap_Bitmap(60, 61, 0, 0, 42, 51);
  Grap_Bitmap(60, 62, 45, 0, 46, 51);
  Grap_Bitmap(60, 63, 88, 0, 52, 51);
  Grap_Bitmap(60, 64, 140, 0, 55, 51);
  Grap_Bitmap(60, 65, 195, 0, 54, 51);
  Grap_Bitmap(60, 66, 249, 0, 45, 51);
  PCX_Unload(60);
  PCX_Load("lights1.pcx", 67, 0);
  PCX_Load("lights2.pcx", 68, 0);
  rings_load_flag = 1;
}

void
rings_unload()
{
  int a;
  for (a = 68; a >= 61; a--)
    PCX_Unload(a);
  rings_load_flag = 0;
}

void
grlch_load()
{
  if (access_load_flag)
    return;
  PCX_Load("grlch.pcx", 60, 0);
  Grap_Bitmap(60, 101, 0, 0, 73, 71);
  Grap_Bitmap(60, 102, 77, 0, 71, 71);
  Grap_Bitmap(60, 103, 147, 0, 76, 71);
  Grap_Bitmap(60, 104, 0, 70, 72, 70);
  Grap_Bitmap(60, 105, 71, 70, 74, 70);
  PCX_Unload(60);
  access_load_flag = 1;
}

void
wallpro_load()
{
  if (access_load_flag)
    return;
  PCX_Load("item2.pcx", 60, 0);
  Grap_Bitmap(60, 101, 2, 2, 92, 47);
  Grap_Bitmap(60, 102, 1, 72, 71, 80);
  Grap_Bitmap(60, 103, 78, 66, 47, 90);
  Grap_Bitmap(60, 104, 139, 69, 58, 83);
  Grap_Bitmap(60, 105, 98, 5, 80, 62);
  Grap_Bitmap(60, 106, 205, 68, 46, 91);
  Grap_Bitmap(60, 107, 194, 0, 66, 66);
  PCX_Unload(60);
  access_load_flag = 1;
}

void
accel_load()
{
  if (access_load_flag)
    return;
  PCX_Load("vase1.pcx", 60, 0);
  Grap_Bitmap(60, 101, 1, 1, 50, 55);
  Grap_Bitmap(60, 102, 54, 1, 50, 55);
  Grap_Bitmap(60, 103, 106, 1, 52, 56);
  Grap_Bitmap(60, 104, 1, 56, 51, 54);
  Grap_Bitmap(60, 105, 52, 57, 52, 54);
  Grap_Bitmap(60, 106, 108, 58, 51, 57);
  PCX_Unload(60);
  access_load_flag = 1;
}

void
shield_load()
{
  if (access_load_flag)
    return;
  PCX_Load("dish1.pcx", 60, 0);
  Grap_Bitmap(60, 101, 2, 3, 50, 114);
  Grap_Bitmap(60, 102, 64, 3, 71, 80);
  Grap_Bitmap(60, 103, 145, 1, 35, 100);
  Grap_Bitmap(60, 104, 185, 0, 63, 87);
  Grap_Bitmap(60, 105, 247, 1, 72, 82);
  PCX_Unload(60);
  access_load_flag = 1;
}

void
shifter_load()
{
  if (access_load_flag)
    return;
  PCX_Load("shift.pcx", 60, 0);
  Grap_Bitmap(60, 101, 1, 1, 60, 56);
  Grap_Bitmap(60, 102, 70, 1, 72, 58);
  Grap_Bitmap(60, 103, 146, 2, 86, 58);
  Grap_Bitmap(60, 104, 1, 59, 87, 59);
  Grap_Bitmap(60, 105, 95, 61, 69, 57);
  PCX_Unload(60);
  access_load_flag = 1;
}

void
mslch_load()
{
  if (access_load_flag)
    return;
  PCX_Load("mslch.pcx", 60, 0);
  Grap_Bitmap(60, 101, 1, 1, 74, 75);
  Grap_Bitmap(60, 102, 78, 1, 84, 75);
  Grap_Bitmap(60, 103, 165, 1, 82, 75);
  Grap_Bitmap(60, 104, 1, 77, 81, 76);
  Grap_Bitmap(60, 105, 84, 77, 84, 75);
  PCX_Unload(60);
  access_load_flag = 1;
}

void
radar_load()
{
  if (access_load_flag)
    return;
  PCX_Load("radar.pcx", 60, 0);
  Grap_Bitmap(60, 101, 116, 5, 85, 67);
  Grap_Bitmap(60, 102, 83, 77, 83, 72);
  Grap_Bitmap(60, 103, 8, 4, 49, 72);
  Grap_Bitmap(60, 104, 61, 4, 50, 72);
  Grap_Bitmap(60, 105, 0, 77, 82, 72);
  PCX_Unload(60);
  access_load_flag = 1;
}

void
laser_load()
{
  if (access_load_flag)
    return;
  PCX_Load("eq5.pcx", 60, 0);
  Grap_Bitmap(60, 101, 4, 1, 58, 76);
  Grap_Bitmap(60, 102, 68, 1, 58, 76);
  Grap_Bitmap(60, 103, 128, 1, 58, 76);
  PCX_Unload(60);
  access_load_flag = 1;
}

void
access_unload()
{
  int a;
  for (a = 109; a >= 101; a--)
    PCX_Unload(a);
  access_load_flag = 0;
}

void
missile_load()
{
  if (missile_load_flag)
    return;
  PCX_Load("missile.pcx", 60, 0);
  Grap_Bitmap(60, 111, 36, 69, 24, 24); //cbomb
  Grap_Bitmap(60, 112, 1, 65, 30, 30);  //dart
  Grap_Bitmap(60, 113, 34, 34, 24, 34); //laser
  Grap_Bitmap(60, 114, 0, 31, 30, 31);  //neutron more powerful
  Grap_Bitmap(60, 115, 0, 0, 30, 31);   //photon
  Grap_Bitmap(60, 116, 36, 1, 31, 32);
  Grap_Bitmap(60, 117, 75, 0, 56, 49);
  Grap_Bitmap(60, 118, 145, 0, 78, 49);
  Grap_Bitmap(60, 119, 234, 0, 82, 49);
  Grap_Bitmap(60, 179, 65, 60, 34, 39); //5GW Laser
  PCX_Unload(60);

  missile_load_flag = 1;
}

void
keystat_load()
{
  if (keystat_load_flag)
    return;
  PCX_Load("keystat.pcx", 60, 0);
  Grap_Bitmap(60, 160, 0, 0, 14, 14);
  Grap_Bitmap(60, 161, 15, 0, 14, 14);
  Grap_Bitmap(60, 162, 29, 0, 14, 14);
  Grap_Bitmap(60, 163, 43, 0, 14, 14);
  Grap_Bitmap(60, 164, 57, 0, 14, 14);
  Grap_Bitmap(60, 165, 71, 0, 14, 14);
  Grap_Bitmap(60, 166, 85, 0, 14, 14);
  Grap_Bitmap(60, 167, 99, 0, 14, 14);
  Grap_Bitmap(60, 168, 113, 0, 14, 14);
  Grap_Bitmap(60, 169, 127, 0, 14, 14);
  Grap_Bitmap(60, 170, 141, 0, 14, 14);
  PCX_Unload(60);
  keystat_load_flag = 1;
}

void
saucer_load()
{
  if (saucer_load_flag)
    return;
  PCX_Load("saucer1.pcx", 60, 0);
  Grap_Bitmap(60, 171, 1, 6, 140, 41);
  Grap_Bitmap(60, 172, 141, 4, 138, 47);
  Grap_Bitmap(60, 173, 2, 56, 142, 45);
  Grap_Bitmap(60, 174, 4, 101, 50, 53);
  Grap_Bitmap(60, 175, 56, 101, 51, 53);
  Grap_Bitmap(60, 176, 109, 101, 49, 53);
  Grap_Bitmap(60, 177, 162, 101, 49, 53);
  Grap_Bitmap(60, 178, 213, 101, 50, 53);
  PCX_Unload(60);
  saucer_load_flag = 1;
}

void
carriers_load()
{
  if (carrier_load_flag)
    return;
  PCX_Load("carriers.pcx", 60, 0);
  Grap_Bitmap(60, 71, 2, 0, 75, 75);
  Grap_Bitmap(60, 72, 83, 0, 75, 75);
  Grap_Bitmap(60, 73, 163, 0, 75, 75);
  Grap_Bitmap(60, 74, 245, 0, 75, 75);
  Grap_Bitmap(60, 75, 2, 75, 75, 112);
  Grap_Bitmap(60, 76, 83, 75, 75, 112);
  Grap_Bitmap(60, 77, 163, 75, 75, 112);
  Grap_Bitmap(60, 78, 245, 75, 75, 75);
  Grap_Bitmap(60, 79, 254, 151, 52, 48);
  PCX_Unload(60);
  carrier_load_flag = 1;
}

void
carriers_unload()
{
  int a;
  for (a = 79; a >= 71; a--)
    PCX_Unload(a);
  carrier_load_flag = 0;
}

void
stalkers_load()
{
  PCX_Load("stalkers.pcx", 60, 0);
  Grap_Bitmap(60, 120, 19, 62, 135, 34);   //Front
  Grap_Bitmap(60, 121, 14, 1, 143, 62);    //Rear
  Grap_Bitmap(60, 122, 1, 139, 165, 61);   //Right
  Grap_Bitmap(60, 123, 152, 190, 168, 59); //Left
  Grap_Bitmap(60, 124, 1, 96, 129, 47);    //Fwd-Left
  Grap_Bitmap(60, 125, 1, 203, 127, 40);   //Fwd-Right
  Grap_Bitmap(60, 126, 160, 86, 147, 50);  //Left-Fwd
  Grap_Bitmap(60, 127, 166, 138, 154, 50); //Right-Fwd
  Grap_Bitmap(60, 128, 177, 1, 143, 43);   //Left-Rear
  Grap_Bitmap(60, 129, 177, 42, 143, 45);  //Right-Rear
  PCX_Unload(60);
}

void
stalker_unload()
{
  int a;
  for (a = 129; a >= 120; a--)
    PCX_Unload(a);
}

void
tanks_load()
{
  PCX_Load("tanks1.pcx", 60, 0);
  Grap_Bitmap(60, 180, 3, 0, 102, 59);     //Front
  Grap_Bitmap(60, 184, 110, 0, 104, 59);   //Rear
  Grap_Bitmap(60, 186, 152, 129, 157, 60); //Right
  Grap_Bitmap(60, 182, 151, 68, 161, 59);  //Left
  Grap_Bitmap(60, 181, 1, 137, 146, 62);   //Fwd- Left
  Grap_Bitmap(60, 183, 1, 68, 153, 63);    //Rear- right
  PCX_Unload(60);

  PCX_Load("tanks2.pcx", 60, 0);
  Grap_Bitmap(60, 187, 17, 1, 145, 62);  //Fwd-Right
  Grap_Bitmap(60, 185, 166, 2, 152, 62); //rear - left
  PCX_Unload(60);
}

void
tank_unload()
{
  int a;
  for (a = 187; a >= 180; a--)
    PCX_Unload(a);
}