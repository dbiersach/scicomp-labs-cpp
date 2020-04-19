#pragma once

#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#include "targetver.h"
#include <tchar.h>
#endif

// Standard SciComp headers
#include <stdio.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include <array>
#include <assert.h>
#include <atomic>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <locale>
#include <memory>
#include <map>
#include <mutex>
#include <random>
#include <sstream>
#include <string>
#include <thread>
#include <time.h>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro5/color.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

/* For CERN ROOT
#include <TApplication.h>
#include <TCanvas.h>
#include <TColor.h>
#include <TDiamond.h>
#include <TF1.h>
#include <TGraph.h>
#include <TH1D.h>
#include <TH1F.h>
#include <TLegend.h>
#include <TMath.h>
#include <TMultiGraph.h>
#include <TNamed.h>
#include <TRandom3.h>
#include <TString.h>
#include <TStyle.h>
*/
