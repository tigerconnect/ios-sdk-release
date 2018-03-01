
/**
 *  Enumeration describing type of TTAttachment.
 */
typedef NS_ENUM(NSUInteger, TTAttachmentType)
{
    /**
     *  No Attachment.
     */
    TTAttachmentTypeNone,
    /**
     *  Attachment is an audio file.
     */
    TTAttachmentTypeAudio,
    /**
     *  Attachment is an image.
     */
    TTAttachmentTypeImage,
    /**
     *  Attachment is a document.
     */
    TTAttachmentTypeDocument,
    /**
     *  Attachment is a video.
     */
    TTAttachmentTypeVideo,
};
