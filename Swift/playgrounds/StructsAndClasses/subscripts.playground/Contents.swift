//: Subscripts are typically used as a shortcut for accessing the member elements in a collection, list, or sequence.

import UIKit
import PlaygroundSupport

struct TimesTable {
  let multiplier: Int
  subscript(index: Int) -> Int {
    return multiplier * index
  }
}

class myViewController : UIViewController {
    
  override func viewDidLoad() {
    super.viewDidLoad()
    
    //initialise the view
    view = UIView()
    view.backgroundColor = .white
    
    //initialise the times table struct
    let threeTimesTable = TimesTable(multiplier: 3)
    
    //composer the label
    let label = UILabel()
    label.frame = CGRect(x: view.frame.midX, y: view.frame.midY, width: 200, height:200)
    label.text = ("Six times three is \(threeTimesTable[6])")
    label.textColor = .black
    
    view.addSubview(label)
    self.view = view
  }
}

// Present the view controller in the Live View window
PlaygroundPage.current.liveView = myViewController()
