//
//  AppDelegate.swift
//  CircularCornerMenu
//
//  Created by Harry O'Brien on 10/07/2019.
//  Copyright © 2019 SociaDevLtd. All rights reserved.
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

  var window: UIWindow?


  func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {

    window = UIWindow()
    window?.makeKeyAndVisible()
    window?.rootViewController = ContainerViewController()

    return true
  }


}

