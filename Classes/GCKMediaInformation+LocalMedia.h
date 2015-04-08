//
//  GCKMediaInformation+LocalMedia.h
//  na
//
//  Created by Isaac Paul on 4/7/14.
//  Copyright (c) 2014 CSORGNAME. All rights reserved.
//

#import <GoogleCast/GCKMediaInformation.h>
#import "Media.h"

@interface GCKMediaInformation (LocalMedia)

+ (GCKMediaInformation *)mediaInformationFromLocalMedia:(Media *)media;

@end
