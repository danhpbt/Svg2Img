# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             freetype-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).             
			#src/main/cpp/src/base/ftbase.c
			#src/main/cpp/src/base/ftbbox.c
			#src/main/cpp/src/base/ftbdf.c
			#src/main/cpp/src/base/ftbitmap.c
			#src/main/cpp/src/base/ftcid.c
			#src/main/cpp/src/base/ftfntfmt.c
			#src/main/cpp/src/base/ftfstype.c
			#src/main/cpp/src/base/ftgasp.c
			#src/main/cpp/src/base/ftglyph.c
			#src/main/cpp/src/base/ftgxval.c
			#src/main/cpp/src/base/ftinit.c
			#src/main/cpp/src/base/ftlcdfil.c
			#src/main/cpp/src/base/ftmm.c
			#src/main/cpp/src/base/ftotval.c
			#src/main/cpp/src/base/ftpatent.c
			#src/main/cpp/src/base/ftpfr.c
			#src/main/cpp/src/base/ftstroke.c
			#src/main/cpp/src/base/ftsynth.c
			#src/main/cpp/src/base/ftsystem.c
			#src/main/cpp/src/base/fttype1.c
			#src/main/cpp/src/base/ftwinfnt.c

			#src/main/cpp/src/autofit/afmodule.c
			
			#src/main/cpp/src/bdf/bdf.c

			#src/main/cpp/src/cache/ftcache.c

			#src/main/cpp/src/cff/cff.c

			#src/main/cpp/src/cid/type1cid.c

			#src/main/cpp/src/gzip/ftgzip.c

			#src/main/cpp/src/bzip2/ftbzip2.c

			#src/main/cpp/src/lzw/ftlzw.c

			#src/main/cpp/src/pcf/pcf.c

			#src/main/cpp/src/pfr/pfr.c

			#src/main/cpp/src/psaux/psaux.c

			#src/main/cpp/src/pshinter/pshinter.c

			#src/main/cpp/src/psnames/psmodule.c

			#src/main/cpp/src/raster/raster.c

			#src/main/cpp/src/sfnt/sfnt.c

			#src/main/cpp/src/smooth/smooth.c

			#src/main/cpp/src/truetype/truetype.c

			#src/main/cpp/src/type1/type1.c

			#src/main/cpp/src/type42/type42.c

			#src/main/cpp/src/winfonts/winfnt.c


            #list file from: https://software.intel.com/en-us/articles/building-freetype-libraries-for-x86-devices-using-the-android-ndk
            src/main/cpp/src/autofit/autofit.c
            src/main/cpp/src/base/basepic.c
            src/main/cpp/src/base/ftapi.c
            src/main/cpp/src/base/ftbase.c
            src/main/cpp/src/base/ftbbox.c
            src/main/cpp/src/base/ftbitmap.c
            src/main/cpp/src/base/ftdbgmem.c
            src/main/cpp/src/base/ftdebug.c
            src/main/cpp/src/base/ftglyph.c
            src/main/cpp/src/base/ftinit.c
            src/main/cpp/src/base/ftpic.c
            src/main/cpp/src/base/ftstroke.c
            src/main/cpp/src/base/ftsynth.c
            src/main/cpp/src/base/ftsystem.c
            src/main/cpp/src/cff/cff.c
            src/main/cpp/src/pshinter/pshinter.c
            src/main/cpp/src/pshinter/pshglob.c
            src/main/cpp/src/pshinter/pshpic.c
            src/main/cpp/src/pshinter/pshrec.c
            src/main/cpp/src/psnames/psnames.c
            src/main/cpp/src/psnames/pspic.c
            src/main/cpp/src/raster/raster.c
            src/main/cpp/src/raster/rastpic.c
            src/main/cpp/src/sfnt/pngshim.c
            src/main/cpp/src/sfnt/sfntpic.c
            src/main/cpp/src/sfnt/ttbdf.c
            src/main/cpp/src/sfnt/ttkern.c
            src/main/cpp/src/sfnt/ttload.c
            src/main/cpp/src/sfnt/ttmtx.c
            src/main/cpp/src/sfnt/ttpost.c
            src/main/cpp/src/sfnt/ttsbit.c
            src/main/cpp/src/sfnt/sfobjs.c
            src/main/cpp/src/sfnt/ttcmap.c
            src/main/cpp/src/sfnt/sfdriver.c
            src/main/cpp/src/smooth/smooth.c
            src/main/cpp/src/smooth/ftspic.c
            src/main/cpp/src/truetype/truetype.c
            src/main/cpp/src/type1/t1driver.c
            src/main/cpp/src/cid/cidgload.c
            src/main/cpp/src/cid/cidload.c
            src/main/cpp/src/cid/cidobjs.c
            src/main/cpp/src/cid/cidparse.c
            src/main/cpp/src/cid/cidriver.c
            src/main/cpp/src/pfr/pfr.c
            src/main/cpp/src/pfr/pfrgload.c
            src/main/cpp/src/pfr/pfrload.c
            src/main/cpp/src/pfr/pfrobjs.c
            src/main/cpp/src/pfr/pfrsbit.c
            src/main/cpp/src/type42/t42objs.c
            src/main/cpp/src/type42/t42parse.c
            src/main/cpp/src/type42/type42.c
            src/main/cpp/src/winfonts/winfnt.c
            src/main/cpp/src/pcf/pcfread.c
            src/main/cpp/src/pcf/pcfutil.c
            src/main/cpp/src/pcf/pcfdrivr.c
            src/main/cpp/src/psaux/afmparse.c
            src/main/cpp/src/psaux/psaux.c
            src/main/cpp/src/psaux/psconv.c
            src/main/cpp/src/psaux/psobjs.c
            src/main/cpp/src/psaux/t1decode.c
            src/main/cpp/src/tools/apinames.c
            src/main/cpp/src/type1/t1afm.c
            src/main/cpp/src/type1/t1gload.c
            src/main/cpp/src/type1/t1load.c
            src/main/cpp/src/type1/t1objs.c
            src/main/cpp/src/type1/t1parse.c
            src/main/cpp/src/bdf/bdfdrivr.c
            src/main/cpp/src/bdf/bdflib.c
            src/main/cpp/src/gzip/ftgzip.c
            src/main/cpp/src/lzw/ftlzw.c

             )

# First, compiler definitions for building the library
add_definitions(-DFT2_BUILD_LIBRARY)
#add_definitions("-DFT_CONFIG_MODULES_H=<ftmodule.h>")

include_directories(
                    src/main/cpp/include
                    src/main/cpp/include/freetype
                    src/main/cpp/include/freetype/config
                    src/main/cpp/include/freetype/internal
                   )




# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       freetype-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )