/**
 * @file doctor.c
 * 
 * @author jevarg
 * @brief Doctor face behavior
 */

#include "doctor.h"
#include "ctv.h"
#include "picture.h"
#include "hyper6.h"
#include "screen.h"

struct drs_st drs[] = {
  { "INDEED YOU HAVE GROWN STRONGER", "*", "DRS_5A.raw" },
  { "DON'T MAKE ME DESTROY YOU!", "*", "DRS_5B.raw" },
  { "QUIT NOW AND JOIN MY LEGION", "*", "DRS_5C.raw" },
  { "IF YOU CHOOSE TO CONTINUE", "THIS FUTILE BATTLE", "DRS_5D.raw" },
  { "I WILL SHOW NO MERCY", "IN YOUR DEMISE", "DRS_5E.raw" },
};

struct drf_st drf[] = {
  { "SO YOU THINK YOU HAVE WON", "*", "DRF_1.raw" },
  { "YES THIS BATTLE IS OVER FOR NOW", "*", "DRF_2.raw" },
  { "BUT THERE WILL BE ANOTHER TIME", "*", "DRF_3.raw" },
  { "BECAUSE I WILL BE BACK!", "*", "DRF_4.raw" },
};

struct drface doc_face[] = {
  { "Welcome to the Grid", "DR_0.raw", "Only the strong survive", "DR_1.raw" },
  { "Impressive", "DR_2.raw", "But you have only begun", "DR_3.raw" },
  { "You look tired", "DR_4.raw", "Why don't you quit and give up", "DR_5.raw" },
  { "So you have brains", "DR_6.raw", "But do you have guts", "DR_7.raw" },
  { "Let me introduce you", "DR_8.raw", "to my Laser Tanks", "DR_25.raw" },

  { "Do you not realize", "DR_10.raw", "Your demise is near", "DR_11.raw" },
  { "Let me introduce you", "DR_8.raw", "to my stalkers", "DR_9.raw" },
  { "Beware cycle rider", "DR_12.raw", "You are trying my patience", "DR_13.raw" },
  { "Impressive", "DR_2.raw", "But can you sustain this pace", "DR_14.raw" },
  { "When you push too far", "DR_15.raw", "I push back", "DR_16.raw" },
  { "We will see if you", "DR_17.raw", "are amuse my my fire pits", "DR_18.raw" },
  { "You are good", "DR_19.raw", "But I will make a slave rider yet", "DR_20.raw" },
  { "You look tired", "DR_4.raw", "I am wearing you down rider", "DR_21.raw" },
  { "Yes you trouble me", "DR_22.raw", "But no one has beaten me yet", "DR_23.raw" },
  { "Your demise is near", "DR_11.raw", "It is inevitable", "DR_24.raw" },

  { "It is pointless", "DR_26.raw", "for you to try to continue", "DR_27.raw" },
  { "Do you really think", "DR_28.raw", "that you have a chance", "DR_29.raw" },
  { "I see destruction in your future", "DR_30.raw", "I will make certain of that", "DR_31.raw" },
  { "Stop this battle join with me", "DR_32.raw", "Together we can destroy the saucers", "DR_33.raw" },
  { "Defy me will you", "DR_49.raw", "Now I will show no mercy", "DR_34.raw" },
  { "Beware cycle rider", "DR_12.raw", "All have failed against me", "DR_35.raw" },
  { "We will see if you", "DR_36.raw", "really are the best", "DR_37.raw" },
  { "Do you not realize", "DR_10.raw", "I am just toying with you", "DR_38.raw" },
  { "When you push too far", "DR_15.raw", "I push back", "DR_16.raw" },
  { "I have something new for you", "DR_39.raw", "Indestructable riders", "DR_40.raw" },
  { "Legions of tanks await you", "DR_41.raw", "Why don't you quit and give up", "DR_5.raw" },
  { "It is inevitable", "DR_24.raw", "that you will be beaten", "DR_43.raw" },
  { "Impressive", "DR_2.raw", "You will be a fine addition to my legion", "DR_44.raw" },
  { "I can play with you no longer", "DR_45.raw", "Prepare to Die", "DR_46.raw" },
  { "Stop", "DR_47.raw", "I can not allow this", "DR_48.raw" }
};

void
DocTalk(char* tx)
{
  int a;
  a = 160 - ((strlen(tx) * 8) / 2);
  display_text(a - 1, 180, tx, 10);
  display_text(a, 181, tx, 255);
}

void
doctor_ender1()
{
  int a, b, ctr = 0;

  doctor_load();
  digital_speed = 9500;
  b = 1;
  for (a = 25; a < picture[131].width - 4; a += 4)
  {

    PCX_Show_Image(160, 100, 131, a);
    delay(10);
  }
  PCX_Show_Image(160, 100, 131, picture[131].width);
  delay(500);
  PCX_Show_Image(163, 95, 135, picture[135].width);
  delay(500);
  PCX_Show_Image(163, 95, 136, picture[136].width); // eyes open

  for (ctr = 0; ctr < 5; ctr++)
  {
    if (digi_flag == 2)
      play_vox(drs[ctr].fname1);
    else
    {
      if (drs[ctr].sent2[0] == '*')
      {
        DocTalk(drs[ctr].sent1);
      }
      else
      {
        DocTalk(drs[ctr].sent1);
        a = 160 - ((strlen(drs[ctr].sent1) * 8) / 2);
        display_text(a - 1, 190, drs[ctr].sent2, 10);
        display_text(a, 191, drs[ctr].sent2, 255);
      }
    }
    if (digi_flag == 2)
    {
      a = 132;
      while (CTV_voice_status)
      {
        PCX_Show_Image(163, 159, a, picture[a].width);
        delay(250);
        a++;
        if (a > 134)
          a = 132;
      }
    }
    else
    {
      b = 0;
      a = 133;
      while (b < 15)
      {
        PCX_Show_Image(163, 159, a, picture[a].width);
        delay(250);
        a++;
        if (a > 134)
          a = 132;
        b++;
      }
    }
    if (digi_flag < 2)
      memcpy(vga_ram, double_buffer_l, SCREEN_BUFFER_SIZE);

    PCX_Show_Image(160, 100, 131, picture[131].width);
    PCX_Show_Image(163, 95, 136, picture[136].width); // eyes open
    delay(150);
    PCX_Show_Image(163, 95, 135, picture[135].width);
    delay(150);
    PCX_Show_Image(160, 100, 131, picture[131].width);
    delay(150);
    PCX_Show_Image(163, 95, 135, picture[135].width);
    delay(150);
    PCX_Show_Image(163, 95, 136, picture[136].width); // eyes open
  }

  if (!digi_flag < 2)
    memcpy(vga_ram, double_buffer_l, SCREEN_BUFFER_SIZE);

  PCX_Show_Image(160, 100, 131, picture[131].width);
  PCX_Show_Image(163, 95, 136, picture[136].width); // eyes open
  delay(1000);
  PCX_Show_Image(163, 95, 135, picture[135].width);
  delay(500);
  PCX_Show_Image(160, 100, 131, picture[131].width);
  delay(500);
  b = 1;
  for (a = picture[131].width - 4; a > 25; a -= 10)
  {

    PCX_Show_Image(160, 100, 131, a);
    delay(10);
    memcpy(vga_ram, double_buffer_l, SCREEN_BUFFER_SIZE);
  }
  digital_speed = 11025;
  doctor_unload();
}

void
doctor_ender2()
{
  int a, b, ctr = 0;

  doctor_load();
  digital_speed = 9500;
  b = 1;
  for (a = 25; a < picture[131].width - 4; a += 4)
  {

    PCX_Show_Image(160, 100, 131, a);
    delay(10);
  }
  PCX_Show_Image(160, 100, 131, picture[131].width);
  delay(500);
  PCX_Show_Image(163, 95, 135, picture[135].width);
  delay(500);
  PCX_Show_Image(163, 95, 136, picture[136].width); // eyes open

  for (ctr = 0; ctr < 5; ctr++)
  {
    if (digi_flag == 2)
      play_vox(drf[ctr].fname1);
    else
    {
      if (drf[ctr].sent2[0] == '*')
      {
        DocTalk(drf[ctr].sent1);
      }
      else
      {
        DocTalk(drf[ctr].sent1);
        a = 160 - ((strlen(drf[ctr].sent1) * 8) / 2);
        display_text(a - 1, 190, drf[ctr].sent2, 10);
        display_text(a, 191, drf[ctr].sent2, 255);
      }
    }
    if (digi_flag == 2)
    {
      a = 132;
      while (CTV_voice_status)
      {
        PCX_Show_Image(163, 159, a, picture[a].width);
        delay(250);
        a++;
        if (a > 134)
          a = 132;
      }
    }
    else
    {
      b = 0;
      a = 133;
      while (b < 15)
      {
        PCX_Show_Image(163, 159, a, picture[a].width);
        delay(250);
        a++;
        if (a > 134)
          a = 132;
        b++;
      }
    }
    if (digi_flag < 2)
      memcpy(vga_ram, double_buffer_l, SCREEN_BUFFER_SIZE);

    PCX_Show_Image(160, 100, 131, picture[131].width);
    PCX_Show_Image(163, 95, 136, picture[136].width); // eyes open
    delay(150);
    PCX_Show_Image(163, 95, 135, picture[135].width);
    delay(150);
    PCX_Show_Image(160, 100, 131, picture[131].width);
    delay(150);
    PCX_Show_Image(163, 95, 135, picture[135].width);
    delay(150);
    PCX_Show_Image(163, 95, 136, picture[136].width); // eyes open
  }

  if (!digi_flag < 2)
    memcpy(vga_ram, double_buffer_l, SCREEN_BUFFER_SIZE);

  PCX_Show_Image(160, 100, 131, picture[131].width);
  PCX_Show_Image(163, 95, 136, picture[136].width); // eyes open
  delay(1000);
  PCX_Show_Image(163, 95, 135, picture[135].width);
  delay(500);
  PCX_Show_Image(160, 100, 131, picture[131].width);
  delay(500);
  b = 1;
  for (a = picture[131].width - 4; a > 25; a -= 10)
  {

    PCX_Show_Image(160, 100, 131, a);
    delay(10);
    memcpy(vga_ram, double_buffer_l, SCREEN_BUFFER_SIZE);
  }
  digital_speed = 11025;
  doctor_unload();
}

void
doctor()
{
  int a, b;
  if (demo_mode)
    return;
  //if(level_num>15) return;
  if (level_num == old_level_num)
    return;
  //old_level_num=level_num;
  doctor_load();
  digital_speed = 9500;
  b = 1;
  for (a = 25; a < picture[131].width - 4; a += 4)
  {

    PCX_Show_Image(160, 100, 131, a);
    render_frame();
    delay(10);
  }
  PCX_Show_Image(160, 100, 131, picture[131].width);
  render_frame();
  delay(500);

  PCX_Show_Image(163, 95, 135, picture[135].width);
  render_frame();
  delay(500);

  PCX_Show_Image(163, 95, 136, picture[136].width); // eyes open
  render_frame();

  if (digi_flag == 2)
    play_vox(doc_face[level_num - 1].fname1);
  else
  {
    DocTalk(doc_face[level_num - 1].sent1);
  }

  if (digi_flag == 2)
  {
    a = 132;
    while (CTV_voice_status)
    {
      PCX_Show_Image(163, 159, a, picture[a].width);
      render_frame();
      delay(250);
      a++;
      if (a > 134)
        a = 132;
    }
  }
  else
  {
    b = 0;
    a = 133;
    while (b < 12)
    {
      PCX_Show_Image(163, 159, a, picture[a].width);
      render_frame();
      delay(250);
      a++;
      if (a > 134)
        a = 132;
      b++;
    }
  }

  if (digi_flag < 2)
    memcpy(vga_ram, double_buffer_l, SCREEN_BUFFER_SIZE);

  PCX_Show_Image(160, 100, 131, picture[131].width);
  PCX_Show_Image(163, 95, 136, picture[136].width); // eyes open
  render_frame();
  delay(250);
  PCX_Show_Image(163, 95, 135, picture[135].width);
  render_frame();
  delay(250);
  PCX_Show_Image(160, 100, 131, picture[131].width);
  render_frame();
  delay(250);
  PCX_Show_Image(163, 95, 135, picture[135].width);
  render_frame();
  delay(250);
  PCX_Show_Image(163, 95, 136, picture[136].width); // eyes open
  render_frame();

  if (digi_flag == 2)
    play_vox(doc_face[level_num - 1].fname2);
  else
  {
    DocTalk(doc_face[level_num - 1].sent2);
  }

  if (digi_flag == 2)
  {
    a = 133;
    while (CTV_voice_status)
    {
      PCX_Show_Image(163, 159, a, picture[a].width);
      render_frame();
      delay(250);
      a++;
      if (a > 134)
        a = 132;
    }
  }
  else
  {
    b = 0;
    a = 133;
    while (b < 12)
    {
      PCX_Show_Image(163, 159, a, picture[a].width);
      render_frame();
      delay(250);
      a++;
      if (a > 134)
        a = 132;
      b++;
    }
  }
  if (digi_flag < 2)
    memcpy(vga_ram, double_buffer_l, SCREEN_BUFFER_SIZE);

  PCX_Show_Image(160, 100, 131, picture[131].width);
  PCX_Show_Image(163, 95, 136, picture[136].width); // eyes open
  render_frame();
  delay(1000);
  PCX_Show_Image(163, 95, 135, picture[135].width);
  render_frame();
  delay(500);
  PCX_Show_Image(160, 100, 131, picture[131].width);
  render_frame();
  delay(500);
  b = 1;
  for (a = picture[131].width - 4; a > 25; a -= 10)
  {

    PCX_Show_Image(160, 100, 131, a);
    render_frame();
    delay(10);
    memcpy(vga_ram, double_buffer_l, SCREEN_BUFFER_SIZE);
  }
  digital_speed = 11025;
  doctor_unload();
  render_frame();
}