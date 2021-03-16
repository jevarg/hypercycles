/**
 * @file doctor.c
 * 
 * @author jevarg
 * @brief Doctor face behavior
 */

#include "doctor.h"

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