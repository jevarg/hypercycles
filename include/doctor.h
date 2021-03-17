#pragma once

struct __attribute__((__packed__)) drs_st
{
  char sent1[41];
  char sent2[41];
  char fname1[14];
};

struct __attribute__((__packed__)) drf_st
{
  char sent1[41];
  char sent2[41];
  char fname1[14];
};

struct __attribute__((__packed__)) drface
{
  char sent1[41];
  char fname1[14];
  char sent2[41];
  char fname2[14];
};

// Globals
extern struct drs_st drs[];
extern struct drf_st drf[];
extern struct drface doc_face[];