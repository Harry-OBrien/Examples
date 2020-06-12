//
//  CircularMenuButton.swift
//  CircularCornerMenu
//
//  Created by Harry O'Brien on 10/07/2019.
//  Copyright © 2019 SociaDevLtd. All rights reserved.
//

import UIKit

class CircleMenu: UIButton {
  private var buttonsCount = 3
  private var duration = 0.7
  
  private var innerButtonRadius = 56
  private var outerButtonRadius = 32
  private var distanceToOuterButton = 100
  
  public init(frame: CGRect,
                normalIcon: String?,
                selectedIcon: String?,
                buttonsCount:Int = 3) {
    super.init(frame: frame)
    
    if let icon = normalIcon {
      setImage(UIImage(named: icon), for: .normal)
    }
    
    if let icon = selectedIcon {
      setImage(UIImage(named: icon), for: .selected)
    }
    
    self.buttonsCount = buttonsCount
  }
  
  required init?(coder aDecoder: NSCoder) {
    fatalError("init(coder:) has not been implemented")
  }
}

class CircularMenuOuterButton: UIButton {

  public init(size: CGSize, distance: Double, angle: Double) {
    super.init(frame: CGRect(origin: CGPoint(x: 0, y: 0), size: size))
    
    backgroundColor = UIColor(red: 0.79, green: 0.24, blue: 0.27, alpha: 1)
    layer.cornerRadius = size.height / 2.0
  }
  
  required init?(coder aDecoder: NSCoder) {
    fatalError("init(coder:) has not been implemented")
  }
  
    /*
    // Only override draw() if you perform custom drawing.
    // An empty implementation adversely affects performance during animation.
    override func draw(_ rect: CGRect) {
        // Drawing code
    }
    */

}
