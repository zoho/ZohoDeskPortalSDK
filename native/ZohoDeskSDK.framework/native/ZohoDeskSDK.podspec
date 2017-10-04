Pod::Spec.new do |s|

# 1
s.platform = :ios
s.ios.deployment_target = '9.0'
s.name = "ZohoDeskSDK"
s.summary = "Zoho Desk"
s.requires_arc = true

# 2
s.version = "0.1.0"

# 3
s.license = { :type => "MIT", :file => "LICENSE" }

# 4 - Replace with your name and e-mail address
s.author = { "rajeshkumar.l" => "rajeshkumar.l@zohocorp.com" }

# For example,
# s.author = { "Joshua Greene" => "jrg.developer@gmail.com" }


# 5 - Replace this URL with your own Github page's URL (from the address bar)
s.homepage = "https://www.zoho.com/desk"

# For example,
# s.homepage = "https://github.com/JRG-Developer/RWPickFlavor"


# 6 - Replace this URL with your own Git URL from "Quick Setup"
s.source = { :git => "https://git.csez.zohocorpin.com/zohodesk/desksdk_bot.git", :tag => "#{s.version}"}

# For example,
# s.source = { :git => "https://github.com/JRG-Developer/RWPickFlavor.git", :tag => "#{s.version}"}


# 7
s.framework = "UIKit"
s.dependency 'RxSwift',    '~> 3.0'
s.dependency 'RxCocoa',    '~> 3.0'
s.dependency 'RxDataSources', '~> 1.0'

#s.dependency 'Alamofire', '~> 2.0'
#s.dependency 'MBProgressHUD', '~> 0.9.0'

# 8
#s.source_files = "ZohoDesk/**/*.{swift}"

# 9
s.resources = "desksdk_bot/**/*.{framework,png,jpeg,jpg,storyboard,xib}"
end
