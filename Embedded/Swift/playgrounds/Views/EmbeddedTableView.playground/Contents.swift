//: A UIKit based Playground for presenting user interface
//https://www.hackingwithswift.com/example-code/uikit/how-to-create-live-playgrounds-in-xcode

import UIKit
import PlaygroundSupport

struct TimesTable {
  let multiplier: Int
  subscript(index: Int) -> Int {
    return multiplier * index
  }
}

class tableView : UITableViewController {
  
  let reasons = ["the labs are great", "the sessions teach new things", "the people are awesome", "the keynote rocks", "I must hug Joe Groff"]
  
  //Initialiser
  override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
    return reasons.count
  }
  
  override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
    // attempt to dequeue a cell
    var cell: UITableViewCell!
    cell = tableView.dequeueReusableCell(withIdentifier: "Cell")
    
    if cell == nil {
      // none to dequeue – make a new one
      cell = UITableViewCell(style: .subtitle, reuseIdentifier: "Cell")
      cell?.accessoryType = .disclosureIndicator
    }
    
    // configure cell here
    let reason = reasons[indexPath.row]
    cell.detailTextLabel?.text = "I want to attend because \(reason)"
    cell.textLabel?.text = "Reason #\(indexPath.row + 1)"
    
    return cell
  }
  
  override func viewDidLoad() {
    super.viewDidLoad()
    //lightweight init
  }
  
  override func viewWillAppear(_ animated: Bool) {
    super.viewWillAppear(animated)
    
    //kick off something big on another thread
    //put 'loading' or similar on screen while waiting for other thread to complete
  }
  
  override func viewDidAppear(_ animated: Bool) {
    super.viewDidAppear(animated)
    
    //start some animation
  }
  
  override func viewWillDisappear(_ animated: Bool) {
    super.viewWillDisappear(animated)
    
    //kick off new thread to clean up some data
  }
  
}

//Init the views
let master = tableView()
let nav = UINavigationController(rootViewController: master)

// Present the view controller in the Live View window
PlaygroundPage.current.liveView = nav
