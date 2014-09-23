//
//  main.c
//  sampleLibAV
//
//  Created by Israel Junior on 23/09/14.
//  Copyright (c) 2014 Israel Junior. All rights reserved.
//

#include <stdio.h>
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/avutil.h>

int main(int argc, const char * argv[])
{

    char file[] = "/Users/israeljrs/Movies/Hillsong-At-the-Cross.mp4";
    
    AVFormatContext *pFormatCtx = NULL;
    av_register_all();
    
    if (avformat_open_input(&pFormatCtx, file, NULL, NULL) != 0) {
        printf("Formato de arquivo não suportado !!!\n");
        return -1;
    }
    
    if (avformat_find_stream_info(pFormatCtx, NULL) < 0) {
        printf("Falha na pesquisa por streaming !!!\n\n");
        return 1;
    }
    
    av_dump_format(pFormatCtx, 0, file, 0);
    
    avformat_close_input(&pFormatCtx);
    
    printf("Sample the use of FFmpeg API !!!\n");
    return 0;
}

