/* HBQueueController.h

   This file is part of the HandBrake source code.
   Homepage: <http://handbrake.fr/>.
   It may be used under the terms of the GNU General Public License. */

#import <Cocoa/Cocoa.h>
#import <Growl/Growl.h>

@class HBAppDelegate;
@class HBController;
@class HBOutputPanelController;
@class HBCore;
@class HBJob;

@interface HBQueueController : NSWindowController <NSToolbarDelegate, NSWindowDelegate, GrowlApplicationBridgeDelegate>

/// The HBCore used for encoding.
@property (nonatomic, readonly) HBCore *core;

@property (nonatomic, unsafe_unretained) HBController *controller;
@property (nonatomic, unsafe_unretained) HBAppDelegate *delegate;

@property (nonatomic, readonly) NSUInteger count;
@property (nonatomic, readonly) NSUInteger pendingItemsCount;
@property (nonatomic, readonly) NSUInteger workingItemsCount;

- (void)addJob:(HBJob *)item;
- (void)addJobsFromArray:(NSArray *)items;

- (BOOL)jobExistAtURL:(NSURL *)url;

- (void)removeAllJobs;
- (void)removeCompletedJobs;

- (void)setEncodingJobsAsPending;

- (IBAction)rip:(id)sender;
- (IBAction)cancelRip:(id)sender;

- (IBAction)togglePauseResume:(id)sender;

@end
