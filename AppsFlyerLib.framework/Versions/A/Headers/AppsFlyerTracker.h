//
//  AppsFlyerTracker.h
//  AppsFlyerLib
//
//  AppsFlyer iOS SDK 4.6.4
//  Copyright (c) 2013 AppsFlyer Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

// In app event names constants
#define AFEventLevelAchieved            @"af_level_achieved"
#define AFEventAddPaymentInfo           @"af_add_payment_info"
#define AFEventAddToCart                @"af_add_to_cart"
#define AFEventAddToWishlist            @"af_add_to_wishlist"
#define AFEventCompleteRegistration     @"af_complete_registration"
#define AFEventTutorial_completion      @"af_tutorial_completion"
#define AFEventInitiatedCheckout        @"af_initiated_checkout"
#define AFEventPurchase                 @"af_purchase"
#define AFEventRate                     @"af_rate"
#define AFEventSearch                   @"af_search"
#define AFEventSpentCredits             @"af_spent_credits"
#define AFEventAchievementUnlocked      @"af_achievement_unlocked"
#define AFEventContentView              @"af_content_view"
#define AFEventListView                 @"af_list_view"
#define AFEventTravelBooking            @"af_travel_booking"
#define AFEventShare                    @"af_share"
#define AFEventInvite                   @"af_invite"
#define AFEventLogin                    @"af_login"
#define AFEventReEngage                 @"af_re_engage"
#define AFEventUpdate                   @"af_update"
#define AFEventOpenedFromPushNotification @"af_opened_from_push_notification"
#define AFEventLocation                 @"af_location_coordinates"
#define AFEventOrderId                  @"af_order_id"
#define AFEventCustomerSegment          @"af_customer_segment"



// In app event parameter names
#define AFEventParamAchievenmentId         @"af_achievement_id"
#define AFEventParamLevel                  @"af_level"
#define AFEventParamScore                  @"af_score"
#define AFEventParamSuccess                @"af_success"
#define AFEventParamPrice                  @"af_price"
#define AFEventParamContentType            @"af_content_type"
#define AFEventParamContentId              @"af_content_id"
#define AFEventParamContentList            @"ad_content_list"
#define AFEventParamCurrency               @"af_currency"
#define AFEventParamQuantity               @"af_quantity"
#define AFEventParamRegistrationMethod     @"af_registration_method"
#define AFEventParamPaymentInfoAvailable   @"af_payment_info_available"
#define AFEventParamMaxRatingValue         @"af_max_rating_value"
#define AFEventParamRatingValue            @"af_rating_value"
#define AFEventParamSearchString           @"af_search_string"
#define AFEventParamDateA                  @"af_date_a"
#define AFEventParamDateB                  @"af_date_b"
#define AFEventParamDestinationA           @"af_destination_a"
#define AFEventParamDestinationB           @"af_destination_b"
#define AFEventParamDescription            @"af_description"
#define AFEventParamClass                  @"af_class"
#define AFEventParamEventStart             @"af_event_start"
#define AFEventParamEventEnd               @"af_event_end"
#define AFEventParamLat                    @"af_lat"
#define AFEventParamLong                   @"af_long"
#define AFEventParamCustomerUserId         @"af_customer_user_id"
#define AFEventParamValidated              @"af_validated"
#define AFEventParamRevenue                @"af_revenue"
#define AFEventParamReceiptId              @"af_receipt_id"
#define AFEventParam1                      @"af_param_1"
#define AFEventParam2                      @"af_param_2"
#define AFEventParam3                      @"af_param_3"
#define AFEventParam4                      @"af_param_4"
#define AFEventParam5                      @"af_param_5"
#define AFEventParam6                      @"af_param_6"
#define AFEventParam7                      @"af_param_7"
#define AFEventParam8                      @"af_param_8"
#define AFEventParam9                      @"af_param_9"
#define AFEventParam10                     @"af_param_10"


typedef enum  {
    EmailCryptTypeNone = 0,
    EmailCryptTypeSHA1 = 1,
    EmailCryptTypeMD5 = 2,
    EmailCryptTypeSHA256 = 3
} EmailCryptType;

/*
 * This delegate should be use if you want to use AppsFlyer conversion data. See AppsFlyer iOS
 */
@protocol AppsFlyerTrackerDelegate <NSObject>

@optional
- (void) onConversionDataReceived:(NSDictionary*) installData;
- (void) onConversionDataRequestFailure:(NSError *)error;
- (void) onAppOpenAttribution:(NSDictionary*) attributionData;
- (void) onAppOpenAttributionFailure:(NSError *)error;

@end

@interface AppsFlyerTracker : NSObject {

    BOOL _isDebug;
    BOOL didCollectIAdData;
    BOOL _useReceiptValidationSandbox;
    BOOL _useUninstallSandbox;
    EmailCryptType emailCryptType;
    NSArray *userEmails;
}

+(AppsFlyerTracker*) sharedTracker;

/* In case you use your own user ID in your app, you can set this property to that ID. */
@property (nonatomic, strong, setter=setCustomerUserID:) NSString *customerUserID;


/* In case you use Custom data and you want to receive it in the raw reports.*/
@property (nonatomic, strong, setter=setAdditionalData:) NSDictionary *customData;

/* Use this property to set your AppsFlyer's dev key. */
@property (nonatomic, strong, setter=setAppsFlyerDevKey:) NSString *appsFlyerDevKey;

/* Use this property to set your app's Apple ID (taken from the app's page on iTunes Connect) */
@property (nonatomic, strong, setter=setAppleAppID:) NSString *appleAppID;

/* 
 * In case of in app purchase events, you can set the currency code your user has purchased with.
 * The currency code is a 3 letter code according to ISO standards. Example: "USD"
 */
@property (nonatomic, strong) NSString *currencyCode;


/* AppsFlyer's SDK send the data to AppsFlyer's servers over HTTPS. You can set the isHTTPS property to NO in order to use regular HTTP. */
//@property BOOL isHTTPS;

/* 
 * AppsFLyer SDK collect Apple's advertisingIdentifier if the AdSupport framework included in the SDK.
 * You can disable this behavior by setting the following property to YES.
 */
@property BOOL disableAppleAdSupportTracking;

/* 
 * Prints our messages to the log. This property should only be used in DEBUG mode. The default value 
 * is NO.
 */
@property (nonatomic, setter = setIsDebug:) BOOL isDebug;


/*
 * Set this flag to NO, to not collect the device name.
 */
@property (nonatomic, setter = setShouldCollectDeviceName:) BOOL shouldCollectDeviceName;


/*
 * Opt-out tracking for specific user
 */
@property BOOL deviceTrackingDisabled;

/*
 * Opt-out tracking for iAd attributions
 */
@property BOOL disableIAdTracking;

/*
 * AppsFlyer delegate. See AppsFlyerTrackerDelegate abvoe
 */
@property (unsafe_unretained, nonatomic) id<AppsFlyerTrackerDelegate> delegate;

/*
 * In app purchase receipt validation Apple environment (production or sandbox). The default value
 * is NO.
 */
@property (nonatomic, setter = setUseReceiptValidationSandbox:) BOOL useReceiptValidationSandbox;


/*
 * Set this flag to test uninstall on Apple environment (production or sandbox). The default value
 * is NO.
 */
@property (nonatomic, setter = setUseUninstallSandbox:) BOOL useUninstallSandbox;

/*
 * Advertising Id (exposed for RemoteDebug)
 */
@property (nonatomic, strong) NSString *advertiserId;

/*
 * Use this to send the User's emails
 */
-(void) setUserEmails:(NSArray *) userEmails withCryptType:(EmailCryptType) type;


/* Track application launch*/
- (void) trackAppLaunch;

/*
 * Use this method to track events in your app like purchases or user actions.
 * Example :
 *      [[AppsFlyer sharedTracker] trackEvent:@"hotel-booked" withValue:"200"];
 */
- (void) trackEvent:(NSString*)eventName withValue:(NSString*)value __attribute__((deprecated));

/*
 * Use this method to track an events with mulitple values. See AppsFlyer's documentation for details. 
 *
 */
- (void) trackEvent:(NSString *)eventName withValues:(NSDictionary*)values;

/*
 * To track in app purchases you can call this method from the completeTransaction: method on 
 * your SKPaymentTransactionObserver.
 */
- (void) validateAndTrackInAppPurchase:(NSString *)productIdentifier
                                 price:(NSString *)price
                              currency:(NSString *)currency
                         transactionId:(NSString *) tranactionId
                  additionalParameters:(NSDictionary *)params
                               success:(void (^)(NSDictionary *response))successBlock
                               failure:(void (^)(NSError *error, id reponse)) failedBlock NS_AVAILABLE(10_7, 7_0);


/*
* To Track location for geo-fencing.
*/
- (void) trackLocation:(double) longitude latitude:(double) latitude;

/*
 * This method returns AppsFLyer's internal user ID (unique for your app)
 */
- (NSString *) getAppsFlyerUID;

/* 
 * In case you want to use AppsFlyer tracking data in your app you can use the following method set a
 * delegate with callback buttons for the tracking data. See AppsFlyerTrackerDelegate above.
 */
- (void) loadConversionDataWithDelegate:(id<AppsFlyerTrackerDelegate>) delegate __attribute__((deprecated));

/*
 * In case you want to track deep linking, call this method from your delegate's openURL method.
 */
- (void) handleOpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication __attribute__((deprecated));

/*
 * In case you want to track deep linking, call this method from your delegate's openURL method with refferer.
 */
- (void) handleOpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication withAnnotation:(id) annotation __attribute__((deprecated));


- (void) handleOpenUrl:(NSURL *) url options:(NSDictionary *)options;
/* 
 * For Universal links iOS 9
 */

- (BOOL) continueUserActivity:(NSUserActivity *) userActivity restorationHandler:(void (^)(NSArray *))restorationHandler NS_AVAILABLE_IOS(9_0);
- (void) didUpdateUserActivity:(NSUserActivity *)userActivity NS_AVAILABLE_IOS(9_0);
- (void) handlePushNotification:(NSDictionary *) pushPayload;


/* 
  Register uninstall - you should register for remote notification and provide Appsflyer the push device token.
*/
- (void) registerUninstall:(NSData *) deviceToken;

/*
 Get SDK version.
*/
- (NSString *) getSDKVersion;



- (void) remoteDebuggingCallWithData:(NSString *) data;

@end
