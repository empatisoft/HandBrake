/*  HBPreset.h $

 This file is part of the HandBrake source code.
 Homepage: <http://handbrake.fr/>.
 It may be used under the terms of the GNU General Public License. */

#import <Foundation/Foundation.h>
#import "HBTreeNode.h"

typedef NS_ENUM(NSUInteger, HBPresetFormat) {
    HBPresetFormatPlist,
    HBPresetFormatJson,
};
/**
 *  HBPreset
 *  Stores a preset dictionary.
 *
 *  An instance of HBPreset can be an actual preset or a folder.
 */
@interface HBPreset : HBTreeNode <NSCopying>

- (instancetype)initWithFolderName:(NSString *)title builtIn:(BOOL)builtIn;

- (instancetype)initWithName:(NSString *)title content:(NSDictionary *)content builtIn:(BOOL)builtIn;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

/**
 *  Initializes a newly allocated preset object initialized with the data found at a given URL.
 *
 *  @param url An URL that identifies a resource containing a string representation of a property list or json in the HandBrake preset format.
 *
 *  @return An initialized preset—which might be different than the original receiver—that contains the preset at URL,
 *  or nil if there is an error or if the contents of the resource are not and HandBrake preset.
 */
- (instancetype)initWithContentsOfURL:(NSURL *)url;

/**
 *  Writes a property list or json representation of the contents of the preset to a given URL.
 *
 *  @param url        The URL to which to write the preset.
 *  @param atomically A flag that specifies whether the output should be written atomically.
 *  @param format     the format of the file to write.
 *  @param removeRoot whether the root preset should be written or not.
 *
 *  @return YES if the location is written successfully, otherwise NO.
 */
- (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically format:(HBPresetFormat)format removeRoot:(BOOL)removeRoot;

/**
 *  Removes unknown keys and normalizes values.
 */
- (void)cleanUp;

/**
 *  The name of the preset.
 */
@property (nonatomic, copy) NSString *name;

/**
 *  A long textual description of the preset.
 */
@property (nonatomic, copy) NSString *presetDescription;

/**
 *  Whether the preset is one of the HandBrake built-in ones or not.
 */
@property (nonatomic, readonly) BOOL isBuiltIn;

/**
 *  Whether the preset is the default one or not. Only one preset can be the default.
 */
@property (nonatomic) BOOL isDefault;

/**
 *  The actual content of the preset.
 */
@property (nonatomic, strong) NSDictionary *content;

/**
 *  A dictionary representation of the preset.
 */
@property (readonly, copy) NSDictionary *dictionary;

@end
