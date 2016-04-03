//
//  main.c
//  sampleLibAV
//
//  Created by Israel Junior on 23/09/14.
//  Copyright (c) 2014 Israel Junior. All rights reserved.
//

#include <stdio.h>
#include <libavformat/avformat.h>
// #include <libavcodec/avcodec.h>
// #include <libavutil/avutil.h>

int main(int argc, const char * argv[])
{

    // char file[] = "/Users/israeljrs/Movies/sample.mp4";
    int nsv, nsa = 0;
    
    AVFormatContext *pFormatCtx = NULL;
    av_register_all();
    
    if (argc != 2) {
        printf("usage: %s <input_file>\n"
               "example program to demonstrate the use of the libavformat API.\n"
               "\n", argv[0]);
        return 1;
    }
    
    if (avformat_open_input(&pFormatCtx, argv[1], NULL, NULL) != 0) {
        printf("Formato de arquivo não suportado !!!\n");
        return -1;
    }
    
    if (avformat_find_stream_info(pFormatCtx, NULL) < 0) {
        printf("Falha na pesquisa por streaming !!!\n\n");
        return 1;
    }
    
    // av_dump_format(pFormatCtx, 0, file, 0);
    // printf("libavformat version : %d\n", avformat_version());
    // printf("Licença : %s\n", avformat_configuration());
    printf("File name : %s\n", pFormatCtx->filename);
    printf("Format Input name : %s\n", pFormatCtx->iformat->name);
    printf("Format Input long name : %s\n", pFormatCtx->iformat->long_name);
    printf("Format Input extension : %s\n", pFormatCtx->iformat->extensions);
    printf("Format Input mimeType : %s\n", pFormatCtx->iformat->mime_type);
    printf("Stream Numbers : %d\n", pFormatCtx->nb_streams);
    for (int i = 0; i < pFormatCtx->nb_streams; i++) {
        if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO) {
            nsv++;
        }
    }
    printf("Number Stream the video : %d\n", nsv);
    
    for (int i = 0; i < pFormatCtx->nb_streams; i++) {
        if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO) {
            nsa++;
        }
    }
    printf("Number Stream the audio : %d\n", nsa);
    
    avformat_close_input(&pFormatCtx);
    
    printf("Sample the use of FFmpeg API !!!\n");
    return 0;
}

