//
//  TTImageView.h
//  TigerText-FrontEnd
//
//  Created by Oren Zitoun on 4/1/14.
//  Copyright (c) 2014 TigerText. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TTMessage;

@protocol TTImageViewDelegate;

/**
 *  TTImageView facilitates loading, resizing and cropping of remote and local images.
 */
@interface TTImageView : UIView

/**
 *  Loads a network image for the given path.
 *
 *  @param pathToNetworkImage image url string.
 *  @param displaySize image view display size.
 *  @param contentMode image content mode display.
 *
 */

- (void)setPathToNetworkImage:(NSString *)pathToNetworkImage
               forDisplaySize:(CGSize)displaySize
                  contentMode:(UIViewContentMode)contentMode;


/**
 *  Loads a network image for the given path.
 *
 *  @param pathToNetworkImage image url string.
 *  @param displaySize image view display size.
 *  @param contentMode image content mode display.
 *  @param borderColor view border color.
 *
 */
- (void)setPathToNetworkImage:(NSString *)pathToNetworkImage
               forDisplaySize:(CGSize)displaySize
                  contentMode:(UIViewContentMode)contentMode
                  borderColor:(UIColor *)borderColor
                  borderWidth:(CGFloat)borderWidth;

/**
 *  Loads a network image for the given path.
 *
 *  @param pathToNetworkImage image url string.
 *  @param displaySize image view display size.
 *  @param contentMode image content mode display.
 *  @param borderColor view border color.
 *  @param circleCrop  will crop the image to a circle.
 *
 */
- (void)setPathToNetworkImage:(NSString *)pathToNetworkImage
               forDisplaySize:(CGSize)displaySize
                  contentMode:(UIViewContentMode)contentMode
                  borderColor:(UIColor *)borderColor
                  borderWidth:(CGFloat)borderWidth
                   circleCrop:(BOOL)circleCrop;

/**
 *  Loads a network image for the given path.
 *
 *  @param pathToNetworkImage image url string.
 *  @param displaySize image view display size.
 *  @param contentMode image content mode display.
 *  @param circleCrop  will crop the image to a circle.
 *
 */
- (void)setPathToNetworkImage:(NSString *)pathToNetworkImage
               forDisplaySize:(CGSize)displaySize
                  contentMode:(UIViewContentMode)contentMode
                   circleCrop:(BOOL)circleCrop;

/**
 *  Loads a network image for the given path.
 *
 *  @param pathToNetworkImage image url string.
 *  @param displaySize image view display size.
 *  @param contentMode image content mode display.
 *  @param cornerRadius sets the corner radius crop.
 *
 */
- (void)setPathToNetworkImage:(NSString *)pathToNetworkImage
               forDisplaySize:(CGSize)displaySize
                  contentMode:(UIViewContentMode)contentMode
                 cornerRadius:(CGFloat)cornerRadius;

/**
 *  Loads a local image for the given file path.
 *
 *  @param pathToImage image url string.
 *  @param displaySize image view display size.
 *  @param contentMode image content mode display.
 *  @param circleCrop  will crop the image to a circle.
 *
 */
- (void)setLocalPathToImage:(NSString *)pathToImage
             forDisplaySize:(CGSize)displaySize
                contentMode:(UIViewContentMode)contentMode
                 circleCrop:(BOOL)circleCrop;

/**
 *  Loads a local image for the given file name.
 *
 *  @param imageName local image file name.
 *  @param displaySize image view display size.
 *  @param contentMode image content mode display.
 *  @param circleCrop  will crop the image to a circle.
 *
 */
- (void)setImageWithName:(NSString *)imageName forDisplaySize:(CGSize)displaySize contentMode:(UIViewContentMode)contentMode circleCrop:(BOOL)circleCrop;

/**
 *  Loads a local image for the given file name.
 *
 *  @param imageName local image file name.
 *  @param displaySize image view display size.
 *  @param contentMode image content mode display.
 *  @param cornerRadius sets the corner radius crop.
 *
 */
- (void)setImageWithName:(NSString *)imageName forDisplaySize:(CGSize)displaySize contentMode:(UIViewContentMode)contentMode cornerRadius:(CGFloat)cornerRadius;

/**
 *  Loads a local image.
 *
 *  @param image image object.
 *  @param displaySize image view display size.
 *  @param contentMode image content mode display.
 *  @param circleCrop  will crop the image to a circle.
 *
 */
- (void)setImage:(UIImage *)image forDisplaySize:(CGSize)displaySize contentMode:(UIViewContentMode)contentMode circleCrop:(BOOL)circleCrop;


/**
 *  Loads a local image.
 *
 *  @param image image object.
 *  @param displaySize  image view display size.
 *  @param contentMode  content mode display.
 *
 */
- (void)setImage:(UIImage *)image forDisplaySize:(CGSize)displaySize contentMode:(UIViewContentMode)contentMode;

/**
 *  Loads a local image.
 *
 *  @param key for image
 *  @param displaySize  image view display size.
 *  @param contentMode  content mode display.
 *  @param roundCorners
 *
 *
 */
- (void)setImageWithKey:(NSString *)key contentMode:(UIViewContentMode)contentMode;


/**
 *  Loads a local image.
 *
 *  @param image image object.
 *  @param displaySize  image view display size.
 *  @param contentMode  content mode display.
 *
 */
- (void)setImage:(UIImage *)image contentMode:(UIViewContentMode)contentMode cacheKey:(NSString *)key;


/**
 *  Sets image view initial default image.
 *
 *  @param initialImage uiimage.
 *
 */
- (void)setInitialImage:(UIImage *)initialImage;

/**
 *  For a message with a downloaded attachment this method will generate and load an image for photos, videos and pdf files
 *
 *  @param message      message object.
 *  @param displaySize  image view display size.
 *  @param contentMode  content mode display.
 *
 *  @return return a BOOL, YES if the image existed on disk and was loaded.
 */
- (BOOL)setMessage:(TTMessage *)message forDisplaySize:(CGSize)displaySize contentMode:(UIViewContentMode)contentMode;

/**
 *  Sets the image
 *
 */
- (void)setImage:(UIImage *)image;

/**
 *  Returns the UIImage object.
 *
 *  @return a 'UIImage' object.
 */
- (UIImage *)getImage;

/**
 *  Returns the UIImageView object.
 *
 *  @return An 'UIImageView' object.
 */
- (UIImageView *)getImageView;

/**
 *  Prepares the view for being reused, should be called if used in a UITableView cell.
 *
 */
- (void)prepareForReuse;

/**
 *  Sets the view width.
 *
 *  @param width view width.
 *
 */
- (void)setNewWidth:(CGFloat)width;


/**
*  Clears the image.
*
*
*/
- (void)clearImage;

- (NSString *)currentNetworkPath;

/**
 *  TTImageViewDelegate.
 *
 */
@property (nonatomic, weak) id<TTImageViewDelegate> delegate;

@end


/**
 *  TTImageViewDelegate.
 */
@protocol TTImageViewDelegate <NSObject>
@optional

/**
 * The image has begun an asynchronous load of the image.
 */
- (void)ttImageViewDidStartLoad:(TTImageView *)imageView;

/**
 * The image has completed an asynchronous download of the image.
 */
- (void)ttImageView:(TTImageView *)imageView didLoadImage:(UIImage *)image;

/**
 * The asynchronous load failed.
 */
- (void)ttImageView:(TTImageView *)imageView didFailWithError:(NSError *)error;

@end
